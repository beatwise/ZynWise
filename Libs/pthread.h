/*
  ZynWise - ZynAddSubFX presets player in vst format

  pthread.h - quick porting
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


#ifndef __PT_
#define __PT_

#include <windows.h>
#define pthread_mutex_t CRITICAL_SECTION
#define pthread_mutex_lock EnterCriticalSection
#define pthread_mutex_unlock LeaveCriticalSection
#define pthread_mutex_init(a, b) InitializeCriticalSection(a)
#define pthread_mutex_destroy DeleteCriticalSection

#endif