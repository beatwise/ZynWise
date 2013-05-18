/*
  ZynWise - ZynAddSubFX presets player in vst format

  gui.h - vst gui 
  Copyright (C) 2013 Alessandro De Santis

  This file is taken from "wisegui library" usage example, file gui.h

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

#ifndef __GUI_
#define __GUI_

#include "vstsdk\aeffeditor.h"
#include "libs\wisegui.h"

class Gui 
	: public AEffEditor, public Window
{
private:
	ERect _rect;

public:
   
	Gui(AudioEffect* effect, const int w, const int h) 
		: AEffEditor(effect), Window(w, h)
	{
		_rect.left		= 0;
		_rect.top		= 0;
		_rect.right		= w - 1;
		_rect.bottom	= h - 1;
	}

	~Gui() {}

	AudioEffect* getEffect()	{ return effect;}
	bool getRect(ERect** rect)	{ *rect = &_rect; return true;}

	bool isOpen()				{ return systemWindow != 0;}
	void idle()					{}

	bool open(void *ptr)		{ systemWindow = ptr; Create(ptr); 
									return true; 
								}

	void close()				{ Destroy(); systemWindow = 0;}
};

#endif // __GUI_