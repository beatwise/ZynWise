/*
  ZynWise - ZynAddSubFX presets player in vst format

  ids.h - identifiers
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

#define knobVolume 0
#define PARAMS_COUNT 1
#define lblPreset2 1024
#define lblPreset3 1025
#define lblPreset4 1026
#define btnPreset2 1027
#define btnPreset3 1028
#define btnPreset1 1029
#define btnPreset4 1030
#define lblPreset1 1031
#define optPreset 1032

#define P0(v) ParamInfo(knobVolume, CTYPE_DOUBLE, 0, 127, v, "Volume", "")
