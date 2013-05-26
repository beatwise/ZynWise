
ZYNWISE
-------

1. ZynWise is a ZynAddSubFx xiz presets player. 

2. It shows how to give ZynAddSubFx a proper vst gui 
   using the wisegui library. 

3. ZynWise is built on top of ZynAddSubFx 2.4.1. 

4. ZynAddSubFx code is mainly located in the following folders:

ZynWise\
    	Globals.h
	DSP\
	Effects\
	Misc\
	Output\
	Params\
	Samples\
	Seq\
	Synth\



CREDITS:
--------

ZynAddSubFx 2.4.1 has the following credits:

Main author:
        Nasca Octavian Paul

Developers:
        Mark McCurry
        Harald Hvaal

Contributors:
        Gerald Folcher (legato, mono notes memory)
        Lars Luthman (zombie fix,jack midi, LASH support)
        Daniel Clemente (with a workaround of X11 repeated key bug)
        Emmanuel Saracco (fix for JACK output)
        Achim Settelmeier (QUERTZ keyboard layout for virtual keyboard)
        Jérémie Andréi (AZERTY keyboard layout, Array index fix, OSS failsafe)
        Alexis Ballier (const char* <-> string mismatch, NULLMidi prototype fix)
        Tobias Doerffel (static-instance variables fix, missing include fix)
        James Morris (Memory leaks in FLTK GUI)
        Stephen Parry (DSSI rebuild)
        Ryan Billing (APhaser)



COMPILING:
----------

1. Download and compile the following libraries:

    fftw3 
    Zlib
    Mxml
    
    They must be compiled so that they statically link 
    to the CRT (flag: /MT )

    These libraries and their headers need to be placed 
    in the folder called Libs:
    
        fftw3.h libfftw.lib
        mxml.h mxml1.lib 
        zconf.h zlib.h zlib.lib 

2. Download a public domain port of dirent.h and dirent.c  
    These files need to be placed in the folder called Libs.

3. Download and compile "Wisegui Library". The headers need 
    to be placed in the folder called wisegui. The library itself
    (renamed to wisegui.lib) and wisegui.h go into the folder Libs. 


4. Get the VSTSDK 2.4 from Steinberg.
    Copy the following files to the vstsdk folder:
	aeffect.h 
	aeffectx.h 
	aeffeditor.h 
	audioeffect.cpp
	audioeffect.h 
	audioeffectx.cpp 
	audioeffectx.h

5. 
    Open "Visual Studio Command Prompt".
    Go to the project root folder.
    Run nmake.
    ZynWise.dll will be placed in the folder called "build".



UPDATE #1
---------

 reworked "hosted parameters" management


