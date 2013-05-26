/*
  ZynWise - ZynAddSubFX presets player in vst format

  zasf.h - ZynAddSubFx wrapper
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


#ifndef __ZASF_
#define __ZASF_

#include <vector>
#include <string>
using namespace std;

#include "libs\wisegui.h"

#include "config.h"
#include "misc\master.h"

class Zasf;
typedef void (Zasf::*PARAMSETTER) (double, bool);

class Zasf
{
public:
	vector<ParamInfo> _programs[PROGRAMS_COUNT];
	PARAMSETTER ParamSetter[PROGRAMS_COUNT][PARAMS_COUNT];

	Master *vmaster;
	char *pbuffer;

	int preset_index;
	string presets[4];

	Zasf();
	~Zasf();

	void CreateDenormalKillBuffer();
	void DestroyDenormalKillBuffer();

	void SelectPreset(int index);
	void SetPreset(int index, string filename);

	void StoreProgram(char **mem, int &size);
	void LoadProgram(char *mem, int size);

	ParamInfo *Param(int program, int index);
	void SetParam(int program, int index, double value);
	void SetMasterVolume(double value, bool normal);
};

bool XizFileChooser(HWND hWnd, string& filename);

#endif // __ZASF_