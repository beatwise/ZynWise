/*
  ZynWise - ZynAddSubFX presets player in vst format

  zasf.cpp - ZynAddSubFx wrapper
  Copyright (C) 2013 Alessandro De Santis

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



#include <sstream>
using namespace std;

#include "zasf.h"

int denormalkillbuf_usercount = 0;

Zasf::Zasf() 
{ 
	CreateDenormalKillBuffer();

	config.init();     
	SAMPLE_RATE				= config.cfg.SampleRate;
    SOUND_BUFFER_SIZE		= config.cfg.SoundBufferSize;
    OSCIL_SIZE				= config.cfg.OscilSize;

    vmaster			= new Master();
    vmaster->swaplr	= 0;

	SelectPreset(0);

	pbuffer = NULL;

	int i = 0;
	_programs[i].push_back(P0(vmaster->Pvolume));
	ParamSetter[i][knobVolume] = &Zasf::SetMasterVolume;
}

ParamInfo *Zasf::Param(int program, int index) 
{
	if (program < 0 || program > PROGRAMS_COUNT)
		return NULL;

	if (index < 0 || index > PARAMS_COUNT)
		return NULL;

	return &_programs[program][index];
}

Zasf::~Zasf() 
{ 
	if (pbuffer)
		delete pbuffer;
	delete vmaster; 
	DestroyDenormalKillBuffer();
}

void Zasf::CreateDenormalKillBuffer()
{
	denormalkillbuf_usercount++;
	if (denormalkillbuf_usercount == 1)
	{		
		denormalkillbuf = new REALTYPE [SOUND_BUFFER_SIZE];
		for(int i = 0; i < SOUND_BUFFER_SIZE; i++)
			denormalkillbuf[i] = (RND - 0.5) * 1e-16;
	}
}

void Zasf::DestroyDenormalKillBuffer()
{
	denormalkillbuf_usercount--;
	if (denormalkillbuf_usercount == 0)
		delete[] denormalkillbuf;
}

void Zasf::SelectPreset(int index)
{
	if (index < 0 || index > 3)
		return;

	preset_index = index;

	vmaster->part[0]->AllNotesOff();

	string filename = presets[index];
	if (filename.length() == 0)
		vmaster->part[0]->defaultsinstrument();
	else
		vmaster->part[0]->loadXMLinstrument(filename.c_str());

	vmaster->part[0]->applyparameters();
}

void Zasf::SetPreset(int index, string filename)
{
	if (index < 0 || index > 3)
		return;

	presets[index] = filename;

	if (index == preset_index)
		SelectPreset(index);
}

void Zasf::StoreProgram(char **mem, int &size)
{
	stringstream bag;
	bag << (int)vmaster->Pvolume << endl;
	bag << preset_index << endl;
	bag << presets[0] << endl;
	bag << presets[1] << endl;
	bag << presets[2] << endl;
	bag << presets[3] << endl;

	if (pbuffer != NULL)
		delete pbuffer;

	size = bag.tellp();
	*mem = pbuffer = new char[size];
	bag.read(pbuffer, size);
}

void Zasf::LoadProgram(char *mem, int size)
{
	stringstream bag;
	bag.write((const char *)mem, size);

	string s;
	int v; 

	getline(bag, s);
	v = atoi(s.c_str());
	vmaster->setPvolume(v);

	getline(bag, s);
	v = atoi(s.c_str());
	preset_index = v;

	getline(bag, presets[0]);
	getline(bag, presets[1]);
	getline(bag, presets[2]);
	getline(bag, presets[3]);

	SelectPreset(preset_index);
}

void Zasf::SetParam(int program, int index, double value)
{
	_programs[program][index].SetNormalValue(value);
	(this->*ParamSetter[program][index])(value, true);
}


void Zasf::SetMasterVolume(double value, bool normal)
{
	if (!normal)
		vmaster->setPvolume(value);
	else
		vmaster->setPvolume((int)(value * 127 + 0.5f));
}


///////////////////////////////////////////////////

bool XizFileChooser(HWND hWnd, string& filename)
{
	OPENFILENAME ofn;
	char buffer[MAX_PATH] = "";

    ZeroMemory(&ofn, sizeof(ofn));

    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = hWnd;
    ofn.lpstrFilter = "Xiz files (*.xiz)\0*.xiz\0";
	ofn.lpstrDefExt = "xiz";
    ofn.lpstrFile = buffer;
    ofn.nMaxFile = MAX_PATH;
    ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;

    if (GetOpenFileName(&ofn))
    {
		filename = string(ofn.lpstrFile);
		return true;
    }

	return false;
}

