/*
  ZynWise - ZynAddSubFX presets player in vst format

  ZynWise.cpp - minimal vst implementation
  Copyright (C) 2013 Alessandro De Santis

  This file is derived from "wisegui library" usage example, file example.cpp

  This program is free software; you can redistribute it and/or modify
  it under the terms of version 2 of the GNU General Public License
  as published by the Free Software Foundation.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License (version 2 or later) for more details.

  You should have received a copy of the GNU General Public License (version 2)
  along with this program; if not, write to the Free Software Foundation,
  Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA

*/

#include <windows.h>

#include "config.h"
#include "ZynWise.h"

#include "MainView.h"

extern void Terminate();

ZynWise::ZynWise(audioMasterCallback audioMaster) 
	: AudioEffectX(audioMaster, PROGRAMS_COUNT, kParamsCount)
{
	Setup();

    if (audioMaster) 
	{
		isSynth(true);
		programsAreChunks(true);
		setNumInputs(INPUTS_COUNT);
        setNumOutputs(OUTPUTS_COUNT);
        setUniqueID(VST_ID);
        canProcessReplacing();

		View *view = new MainView(this);
		view->SetData(&_zasf);
		_gui = new Gui(this, GUI_WIDTH, GUI_HEIGHT);
		_gui->SetView(view);
		setEditor(_gui);
    }
}

ZynWise::~ZynWise() 
{
	Terminate();
}

VstInt32 ZynWise::canDo (char* text)
{
	if (!strcmp(text, "receiveVstEvents"))
		return 1;
	if (!strcmp(text, "receiveVstMidiEvent"))
		return 1;
	if (!strcmp (text, "midiProgramNames"))
		return 1;
	return -1;
}

//----------------------------------------------------------
// PROGRAMS MANAGEMENT

bool ZynWise::getProgramNameIndexed(
	VstInt32 category, VstInt32 index, char* text)
{	
	_snprintf(text, 16, "prg %d", index);
	return true;
}

void ZynWise::getProgramName(char *name) 
{
	_snprintf(name, 16, "prg %d", curProgram);
}


void ZynWise::setProgram(VstInt32 program) 
{
	if (program < PROGRAMS_COUNT)
	{
		// set the parameters to default values
		for (int i = 0; i < kParamsCount; i++)			
			_programs[program][i].Init();

		curProgram = program;	

		// update all the controls' values
		if (_gui != NULL)
			_gui->RequestViewUpdate();
	}
}

VstInt32 ZynWise::getProgram() 
{
	return curProgram;
}


//----------------------------------------------------------
// AUDIO

void ZynWise::process(float **inputs, float **outputs, long frames)
{
    processReplacing(inputs, outputs, frames);
}

void ZynWise::processReplacing(float **inputs, float **outputs, VstInt32 frames)
{
	// original ZynAddSubFx code

    float *outl = outputs[0];
    float *outr = outputs[1];
    //pthread_mutex_lock(&vmaster->mutex);
	EnterCriticalSection(&_zasf.vmaster->mutex);

    _zasf.vmaster->GetAudioOutSamples(frames, 
		(int) getSampleRate(), outl, outr);
    //pthread_mutex_unlock(&vmaster->mutex);
	LeaveCriticalSection(&_zasf.vmaster->mutex);
}

//----------------------------------------------------------
// PARAMETERS DEFINITIONS

void ZynWise::getParameterLabel(VstInt32 index, char* label)
{
	strncpy(label, _programs[curProgram][index].GetLabel().c_str(), 
		kVstMaxParamStrLen);
}

void ZynWise::getParameterDisplay(VstInt32 index, char* text)
{
	_snprintf(text, kVstMaxParamStrLen - 1, "%f", 
		_programs[curProgram][index].GetValue());	
}

void ZynWise::getParameterName(VstInt32 index, char* text)
{
	strncpy(text, _programs[curProgram][index].GetName().c_str(), 
		kVstMaxParamStrLen);
}

bool ZynWise::getParameterProperties(VstInt32 index, VstParameterProperties* p) 
{
	if (index >= kParamsCount)
		return false;

	p->flags = kVstParameterSupportsDisplayIndex;
	p->displayIndex = index;	
	p->minInteger = (VstInt32)_programs[curProgram][index].GetMin();
	p->maxInteger = (VstInt32)_programs[curProgram][index].GetMax();

	if (_programs[curProgram][index].GetType() == CTYPE_DOUBLE)
	{
		p->flags |= kVstParameterUsesFloatStep;
		p->stepFloat = 1;
		p->largeStepFloat = 1;
	}
	else if (_programs[curProgram][index].GetType() == CTYPE_BOOL)
	{
		p->flags |= (kVstParameterIsSwitch 
			| kVstParameterUsesIntStep);
		p->stepInteger = 1;
		p->largeStepInteger = 1;
	}
	else if (_programs[curProgram][index].GetType() == CTYPE_INT)
	{
		p->flags |= kVstParameterUsesFloatStep;
		p->stepFloat = 1;
		p->largeStepFloat = 1;
		//p->flags |= kVstParameterUsesIntStep; 
		//p->stepInteger = 1;
		//p->largeStepInteger = 1;
	}

	return true; 
}

//----------------------------------------------------------
// PARAMETERS MANAGEMENT

void ZynWise::setParameter(VstInt32 index, float value)
{
	if (index < 0 || index >= kParamsCount)
		return;

	_programs[curProgram][index].SetNormalValue(value);

	if (_gui)
	{
		// update the control's value
		_gui->RequestControlUpdate(index, value);
	}
}

float ZynWise::getParameter(VstInt32 index)
{
	if (0 <= index && index < kParamsCount)
		return _programs[curProgram][index].GetNormalValue();
	return 0.f;
}

//----------------------------------------------------------
// WISEGUI STUFF

// The user has changed some control's value
void ZynWise::ParamChanged(int index, double value)
{
	if (index < 0)
		return;

	if (index < kParamsCount)
		// notify the host
		setParameterAutomated(index, (float)value);
	else
	{
		_gui->GetView()->OnUpdate(index, value);			
	}
}

// The gui asks for a normalized parameter's value 
double ZynWise::GetParamValue(int index, bool normal)
{
	if (! (0 <= index && index < kParamsCount) )
		return 0.f;

	if (normal)
		return _programs[curProgram][index].GetNormalValue();
	
	return _programs[curProgram][index].GetValue();
}

// The gui asks for a parameter's info
ParamInfo *ZynWise::GetParamInfo(int index)
{
	if (0 <= index && index < kParamsCount)
		return &_programs[curProgram][index];

	return NULL;
}


//----------------------------------------------------------
// SETUP PROGRAMS & PARAMETERS VALUES

void ZynWise::Setup()
{
	// params are inserted in the order in which they 	
	// are defined in ids.h
	int i = 0;

	// Program 1
	_programs[i].push_back(P0(64));
}

VstInt32 ZynWise::setChunk(void* data, VstInt32 byteSize, bool isPreset)						   
{
	_zasf.LoadProgram((char *)data, byteSize);
	if (_gui)
		_gui->GetView()->OnLoad();
	return 0;
}

VstInt32 ZynWise::getChunk(void **data, bool isPreset)
{
	int size;
	_zasf.StoreProgram((char**)data, size);
	return size;
}

//----------------------------------------------------------
// MIDI INPUT

VstInt32 ZynWise::processEvents(VstEvents *events)
{
	// original ZynAddSubFx code
	// note: delta frames ??

    for(int i = 0; i < events->numEvents; i++) 
	{
        if((events->events[i])->type != kVstMidiType)
            continue;

        VstMidiEvent  *ev   = (VstMidiEvent *)events->events[i];
        unsigned char *data = (unsigned char *)ev->midiData;
        int status			= data[0] / 16;
        int cmdchan			= data[0] & 0x0f;
        int cntl;

        //pthread_mutex_lock(&vmaster->mutex);
		EnterCriticalSection(&_zasf.vmaster->mutex);

        switch(status) 
		{
        case 0x8:
            _zasf.vmaster->NoteOff(cmdchan, data[1] & 0x7f);
            break;
        case 0x9:
            if(data[2] == 0)
                _zasf.vmaster->NoteOff(cmdchan, data[1] & 0x7f);
            else
                _zasf.vmaster->NoteOn(cmdchan, data[1] & 0x7f, data[2] & 0x7f);
            break;
        //case 0xB:
        //    cntl = Midi->getcontroller(data[1] & 0x7f);
        //    vmaster->SetController(cmdchan, cntl, data[2] & 0x7f);
        //    break;
        case 0xE:
            _zasf.vmaster->SetController(
				cmdchan, C_pitchwheel, data[1] 
					+ data[2] * (long int) 128 - 8192);
            break;
        }

        //pthread_mutex_unlock(&vmaster->mutex);
		LeaveCriticalSection(&_zasf.vmaster->mutex);
    }

    return 1;
}
