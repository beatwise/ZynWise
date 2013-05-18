/*
  ZynWise - ZynAddSubFX presets player in vst format

  config.h - vst configuration data
  Copyright (C) 2013 Alessandro De Santis

  This file is derived from "wisegui library" usage example, file config.h

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

#ifndef __CFG_
#define __CFG_

#define VST_ID			'ZnWs'
#define EFFECT_NAME		"ZynWise"
#define VENDOR_STRING	"ZynWise demo gui"
#define PRODUCT_STRING	"ZynWise demo gui"
#define VENDOR_VERSION	1000

#define GUI_WIDTH		400
#define GUI_HEIGHT		256

#define PROGRAMS_COUNT	1

#define INPUTS_COUNT	0
#define OUTPUTS_COUNT	2

#include "ids.h"
#define kParamsCount	PARAMS_COUNT


#endif


