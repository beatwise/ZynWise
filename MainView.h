/*
  ZynWise - ZynAddSubFX presets player in vst format

  MainView.h 
  Copyright (C) 2013 Alessandro De Santis

  This is an auto-generated file

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

// AUTO GENERATED CODE
#ifndef __MainView_
#define __MainView_

#include "ids.h"
#include "bgeres.h"
#include "wisegui.h"

class MainView : public View
{
public:
    MainView(ControlListener *cl) : View(cl)
    {
		SetSize(400, 256);
		SetImageId(IMG_MainView);

		Label *ctl_lblPreset2 = new Label();
		ctl_lblPreset2->SetSize(248, 24);
		ctl_lblPreset2->SetLocation(44, 130);
		ctl_lblPreset2->SetParamIndex(lblPreset2);
		ctl_lblPreset2->SetImageId(IMG_LongLabel);
		ctl_lblPreset2->SetAlignment(0);
		ctl_lblPreset2->SetFontFamily("Verdana");
		ctl_lblPreset2->SetFontSize(10);
		ctl_lblPreset2->SetFontColor(255, 255, 255, 255);
		Add(ctl_lblPreset2);

		Label *ctl_lblPreset3 = new Label();
		ctl_lblPreset3->SetSize(248, 24);
		ctl_lblPreset3->SetLocation(44, 160);
		ctl_lblPreset3->SetParamIndex(lblPreset3);
		ctl_lblPreset3->SetImageId(IMG_LongLabel);
		ctl_lblPreset3->SetAlignment(0);
		ctl_lblPreset3->SetFontFamily("Verdana");
		ctl_lblPreset3->SetFontSize(10);
		ctl_lblPreset3->SetFontColor(255, 255, 255, 255);
		Add(ctl_lblPreset3);

		Label *ctl_lblPreset4 = new Label();
		ctl_lblPreset4->SetSize(248, 24);
		ctl_lblPreset4->SetLocation(44, 190);
		ctl_lblPreset4->SetParamIndex(lblPreset4);
		ctl_lblPreset4->SetImageId(IMG_LongLabel);
		ctl_lblPreset4->SetAlignment(0);
		ctl_lblPreset4->SetFontFamily("Verdana");
		ctl_lblPreset4->SetFontSize(10);
		ctl_lblPreset4->SetFontColor(255, 255, 255, 255);
		Add(ctl_lblPreset4);

		Button *ctl_btnPreset2 = new Button();
		ctl_btnPreset2->SetSize(64, 24);
		ctl_btnPreset2->SetLocation(297, 130);
		ctl_btnPreset2->SetParamIndex(btnPreset2);
		ctl_btnPreset2->SetImageId(IMG_LoadButton);
		Add(ctl_btnPreset2);

		Button *ctl_btnPreset3 = new Button();
		ctl_btnPreset3->SetSize(64, 24);
		ctl_btnPreset3->SetLocation(297, 160);
		ctl_btnPreset3->SetParamIndex(btnPreset3);
		ctl_btnPreset3->SetImageId(IMG_LoadButton);
		Add(ctl_btnPreset3);

		Button *ctl_btnPreset1 = new Button();
		ctl_btnPreset1->SetSize(64, 24);
		ctl_btnPreset1->SetLocation(297, 100);
		ctl_btnPreset1->SetParamIndex(btnPreset1);
		ctl_btnPreset1->SetImageId(IMG_LoadButton);
		Add(ctl_btnPreset1);

		Button *ctl_btnPreset4 = new Button();
		ctl_btnPreset4->SetSize(64, 24);
		ctl_btnPreset4->SetLocation(297, 190);
		ctl_btnPreset4->SetParamIndex(btnPreset4);
		ctl_btnPreset4->SetImageId(IMG_LoadButton);
		Add(ctl_btnPreset4);

		Label *ctl_lblPreset1 = new Label();
		ctl_lblPreset1->SetSize(248, 24);
		ctl_lblPreset1->SetLocation(44, 100);
		ctl_lblPreset1->SetParamIndex(lblPreset1);
		ctl_lblPreset1->SetImageId(IMG_LongLabel);
		ctl_lblPreset1->SetAlignment(0);
		ctl_lblPreset1->SetFontFamily("Verdana");
		ctl_lblPreset1->SetFontSize(10);
		ctl_lblPreset1->SetFontColor(255, 255, 255, 255);
		Add(ctl_lblPreset1);

		Knob *ctl_knobVolume = new Knob();
		ctl_knobVolume->SetSize(32, 32);
		ctl_knobVolume->SetLocation(311, 33);
		ctl_knobVolume->SetParamIndex(knobVolume);
		ctl_knobVolume->SetImageId(IMG_Knob);
		ctl_knobVolume->SetMin(0);
		ctl_knobVolume->SetMax(127);
		ctl_knobVolume->SetFrames(31);
		Add(ctl_knobVolume);

		VSwitch *ctl_optPreset = new VSwitch();
		ctl_optPreset->SetSize(24, 114);
		ctl_optPreset->SetLocation(18, 98);
		ctl_optPreset->SetParamIndex(optPreset);
		ctl_optPreset->SetImageId(IMG_optPresetSelector);
		ctl_optPreset->SetMin(0);
		ctl_optPreset->SetMax(3);
		ctl_optPreset->SetOptionsCount(4);
		Add(ctl_optPreset);


    }    
	virtual void OnLoad();
	virtual void OnUpdate(int index, double value);
};
#endif
