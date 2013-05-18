/*
  ZynWise - ZynAddSubFX presets player in vst format

  ZynWise.h - minimal vst implementation
  Copyright (C) 2013 Alessandro De Santis

  This file is derived from "wisegui library" usage example, file example.h

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

#ifndef __ZYNWISE_
#define __ZYNWISE_

#include "vstsdk/audioeffectx.h"
#include "config.h"
#include "gui.h"

#include <stdio.h>
#include <vector>
using namespace std;

#include "libs\wisegui.h"
#include "zasf.h"

class ZynWise 
	: public AudioEffectX, public ControlListener
{
    public:
        ZynWise(audioMasterCallback audioMaster);
        ~ZynWise();

		VstInt32 canDo(char* text);

        void process(float **inputs, float **outputs, long frames);
        void processReplacing(float **inputs, float **outputs, VstInt32 frames);
		VstInt32 processEvents(VstEvents *events);


		bool getEffectName(char* name) 
			{ _snprintf(name, 31, EFFECT_NAME); return true; }
		virtual VstInt32 getVendorVersion() 
			{ return VENDOR_VERSION; }
		bool getVendorString(char *txt) 
			{strcpy(txt, VENDOR_STRING); return true;}
		bool getProductString(char *txt) 
			{strcpy(txt, PRODUCT_STRING); return true;}

		void Setup();
		bool getProgramNameIndexed(VstInt32 category, VstInt32 index, char* text);
		void getProgramName(char *name);
		void setProgramName(char *name){}
		VstInt32 getProgram();
		void setProgram(VstInt32 program);

		VstInt32 setChunk(void* data, VstInt32 byteSize, bool isPreset);
		VstInt32 getChunk(void **data, bool isPreset);

		void setParameter (VstInt32 index, float value);
		float getParameter (VstInt32 index);

		void getParameterLabel (VstInt32 index, char* label);
		void getParameterDisplay (VstInt32 index, char* text);
		void getParameterName (VstInt32 index, char* text);
		bool getParameterProperties(VstInt32 index, VstParameterProperties* p);

		// WiseGui's ControlListener
		void ParamChanged(int, double);
		double GetParamValue(int index, bool normal = true);
		ParamInfo *GetParamInfo(int index);

		vector<ParamInfo> _programs[PROGRAMS_COUNT];
		Gui *_gui;

		Zasf _zasf;
};

#endif // __ZYNWISE_

