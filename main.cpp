/*
  ZynWise - ZynAddSubFX presets player in vst format

  main.cpp - vst entry point
  Copyright (C) 2013 Alessandro De Santis

  This file is taken from "wisegui library" usage example, file main.cpp

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

#include "ZynWise.h"
#include "libs\wisegui.h"

void Init()
{
	WiseGui_Init();
}

void Terminate()
{
	WiseGui_Terminate();
}

extern "C" 
{
	__declspec(dllexport)
	AEffect* VSTPluginMain(audioMasterCallback audioMaster)
	{ 
		Init();
		AudioEffect *vst = new ZynWise(audioMaster);
		return vst->getAeffect();
	}
}

BOOL WINAPI DllMain(HINSTANCE hInst, DWORD dwReason, LPVOID lpvReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		g_hInstance = hInst;
	}
	else if (dwReason == DLL_PROCESS_DETACH) 
	{
	}
	
    return 1;
}