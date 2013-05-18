/*
  ZynWise - ZynAddSubFX presets player in vst format

  MainView.cpp - vst gui events handler
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

#include "zasf.h"
#include "MainView.h"

void MainView::OnLoad() 
{
	Zasf *zasf = (Zasf *)GetData();
	ControlListener *cl = GetListener();
	Master *master = zasf->vmaster;

	// volume
	SetControlValue(knobVolume, master->Pvolume, false);

	// preset selector
	SetControlValue(optPreset, zasf->preset_index, false);

	// labels
	char drive[16], folder[256], fn[128], e[16], s[65];

	//todo: fine tune these numbers "64"
	_splitpath_s(zasf->presets[0] .c_str(), 
		drive, 16, folder, 256, fn, 128, e, 16);
	_snprintf(s, 64, "%s", fn);
	SetControlValue(lblPreset1, (int)s);

	_splitpath_s(zasf->presets[1] .c_str(), 
		drive, 16, folder, 256, fn, 128, e, 16);
	_snprintf(s, 64, "%s", fn);
	SetControlValue(lblPreset2, (int)s);

	_splitpath_s(zasf->presets[2] .c_str(), 
		drive, 16, folder, 256, fn, 128, e, 16);
	_snprintf(s, 64, "%s", fn);
	SetControlValue(lblPreset3, (int)s);

	_splitpath_s(zasf->presets[3] .c_str(), 
		drive, 16, folder, 256, fn, 128, e, 16);
	_snprintf(s, 64, "%s", fn);
	SetControlValue(lblPreset4, (int)s);
}

void MainView::OnUpdate(int index, double value) 
{
	Zasf *zasf = (Zasf *)GetData();
	ControlListener *cl = GetListener();
	Master *master = zasf->vmaster;

	if (index == knobVolume)
	{		
		int vol = cl->GetParamValue(knobVolume, false);		
		master->setPvolume(vol);
	}
	else if (index == btnPreset1)
	{
		string filename;
		if (XizFileChooser(GetWindowHandle(), filename))
		{
			char drive[16], folder[256], fn[128], e[16];
			_splitpath_s(filename.c_str(), 
				drive, 16, folder, 256, fn, 128, e, 16);

			char s[65];
			_snprintf(s, 64, "%s", fn);
			SetControlValue(lblPreset1, (int)s);

			zasf->SetPreset(0, filename);
		}
	}
	else if (index == btnPreset2)
	{
		string filename;
		if (XizFileChooser(GetWindowHandle(), filename))
		{
			char drive[16], folder[256], fn[128], e[16];
			_splitpath_s(filename.c_str(), 
				drive, 16, folder, 256, fn, 128, e, 16);

			char s[65];
			_snprintf(s, 64, "%s", fn);
			SetControlValue(lblPreset2, (int)s);

			zasf->SetPreset(1, filename);
		}
	}
	else if (index == btnPreset3)
	{
		string filename;
		if (XizFileChooser(GetWindowHandle(), filename))
		{
			char drive[16], folder[256], fn[128], e[16];
			_splitpath_s(filename.c_str(), 
				drive, 16, folder, 256, fn, 128, e, 16);

			char s[65];
			_snprintf(s, 64, "%s", fn);
			SetControlValue(lblPreset3, (int)s);

			zasf->SetPreset(2, filename);
		}
	}
	else if (index == btnPreset4)
	{
		string filename;
		if (XizFileChooser(GetWindowHandle(), filename))
		{
			char drive[16], folder[256], fn[128], e[16];
			_splitpath_s(filename.c_str(), 
				drive, 16, folder, 256, fn, 128, e, 16);

			char s[65];
			_snprintf(s, 64, "%s", fn);
			SetControlValue(lblPreset4, (int)s);

			zasf->SetPreset(3, filename);
		}
	}

	else if (index == optPreset)
	{
		ControlPtr opt = GetControl(index);
		int value = opt->GetValue();
		zasf->SelectPreset(value);
	}
}

