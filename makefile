
COMPILE = cl.exe
LINK = link.exe

TARGET = build\ZynWise.dll 

INCLUDES = /I "Libs"
DEFINES = /D "_CRT_SECURE_NO_WARNINGS" /D "VST_API" /D "OS_WINDOWS"

LIBS = wisegui.lib libfftw.lib mxml1.lib zlib.lib gdiplus.lib \
    kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib \
    advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib \
    odbc32.lib odbccp32.lib \

RES_SRC = "main.rc"
RES_OBJ = "build\main.res" 

CFLAGS = /O2 /Oi /GL \
    /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_WINDLL" \
    /FD /EHsc /MT /Gy /Fobuild\ /W3 /nologo /c /TP /fp:fast \
    /D "ZYNWISE_EXPORTS" \
    /errorReport:prompt \

LDFLAGS = /INCREMENTAL:NO /NOLOGO \
    /DLL /SUBSYSTEM:WINDOWS /OPT:REF /OPT:ICF /LTCG \
    /DYNAMICBASE /NXCOMPAT /MACHINE:X86 \
    /LIBPATH:Libs /DEF:"zynwise.def" \
    /MANIFEST \
    /MANIFESTFILE:"build\ZynWise.dll.intermediate.manifest" \
    /MANIFESTUAC:"level='asInvoker' uiAccess='false'" \
    /ERRORREPORT:PROMPT \

DSP_SRCS = \
    Dsp\AnalogFilter.cpp \
    Dsp\FFTwrapper.cpp \
    Dsp\Filter.cpp \
    Dsp\FormantFilter.cpp \
    Dsp\SVFilter.cpp \
    Dsp\Unison.cpp \
    
EFFECTS_SRCS = \
    Effects\Alienwah.cpp \
    Effects\Chorus.cpp \
    Effects\Distorsion.cpp \
    Effects\DynamicFilter.cpp \
    Effects\Echo.cpp \
    Effects\Effect.cpp \
    Effects\EffectLFO.cpp \
    Effects\EffectMgr.cpp \
    Effects\EQ.cpp \
    Effects\Phaser.cpp \
    Effects\Reverb.cpp \
    
MISC_SRCS = \
    Misc\Bank.cpp \
    Misc\Config.cpp \
    Misc\Dump.cpp \
    Misc\Master.cpp \
    Misc\Microtonal.cpp \
    Misc\Part.cpp \
    Misc\Util.cpp \
    Misc\XMLwrapper.cpp \
    
PARAMS_SRCS = \
    Params\ADnoteParameters.cpp \
    Params\Controller.cpp \
    Params\EnvelopeParams.cpp \
    Params\FilterParams.cpp \
    Params\LFOParams.cpp \
    Params\PADnoteParameters.cpp \
    Params\Presets.cpp \
    Params\PresetsArray.cpp \
    Params\PresetsStore.cpp \
    Params\SUBnoteParameters.cpp \
    
SAMPLES_SRCS = \
    Samples\Sample.cpp \
    
SEQ_SRCS = \
    Seq\MIDIEvents.cpp \
    Seq\MIDIFile.cpp \
    Seq\Sequencer.cpp \
    
SYNTH_SRCS = \
    Synth\ADnote.cpp \
    Synth\Envelope.cpp \
    Synth\LFO.cpp \
    Synth\OscilGen.cpp \
    Synth\PADnote.cpp \
    Synth\Resonance.cpp \
    Synth\SUBnote.cpp \
    
DIRENT_SRCS = \
    Libs\dirent.c \
    
OUTPUT_SRCS = \
    Output\Recorder.cpp \
    Output\WAVaudiooutput.cpp \
    
ZYNWISE_SRCS = \
    ZynWise.cpp \
    MainView.cpp \
    zasf.cpp \
    main.cpp \

VST_SRCS = \
    vstsdk\audioeffect.cpp \
    vstsdk\audioeffectx.cpp \

DSP_OBJS = \
    build\AnalogFilter.obj \
    build\FFTwrapper.obj \
    build\Filter.obj \
    build\FormantFilter.obj \
    build\SVFilter.obj \
    build\Unison.obj \
    
EFFECTS_OBJS = \
    build\Alienwah.obj \
    build\Chorus.obj \
    build\Distorsion.obj \
    build\DynamicFilter.obj \
    build\Echo.obj \
    build\Effect.obj \
    build\EffectLFO.obj \
    build\EffectMgr.obj \
    build\EQ.obj \
    build\Phaser.obj \
    build\Reverb.obj \
    
MISC_OBJS = \
    build\Bank.obj \
    build\Config.obj \
    build\Dump.obj \
    build\Master.obj \
    build\Microtonal.obj \
    build\Part.obj \
    build\Util.obj \
    build\XMLwrapper.obj \
    
PARAMS_OBJS = \
    build\ADnoteParameters.obj \
    build\Controller.obj \
    build\EnvelopeParams.obj \
    build\FilterParams.obj \
    build\LFOParams.obj \
    build\PADnoteParameters.obj \
    build\Presets.obj \
    build\PresetsArray.obj \
    build\PresetsStore.obj \
    build\SUBnoteParameters.obj \
    
SAMPLES_OBJS = \
    build\Sample.obj \
    
SEQ_OBJS = \
    build\MIDIEvents.obj \
    build\MIDIFile.obj \
    build\Sequencer.obj \
    
SYNTH_OBJS = \
    build\ADnote.obj \
    build\Envelope.obj \
    build\LFO.obj \
    build\OscilGen.obj \
    build\PADnote.obj \
    build\Resonance.obj \
    build\SUBnote.obj \
    
DIRENT_OBJS = \
    build\dirent.obj \
    
OUTPUT_OBJS = \
    build\Recorder.obj \
    build\WAVaudiooutput.obj \
    
ZYNWISE_OBJS = \
    build\ZynWise.obj \
    build\MainView.obj \
    build\zasf.obj \
    build\main.obj \
    
VST_OBJS = \
    build\audioeffect.obj \
    build\audioeffectx.obj \

SRCS = $(DSP_SRCS) $(EFFECTS_SRCS) $(MISC_SRCS) $(PARAMS_SRCS) \
    $(SAMPLES_SRCS) $(SEQ_SRCS) $(SYNTH_SRCS) $(DIRENT_SRCS) \
    $(OUTPUT_SRCS) $(VST_SRCS) $(ZYNWISE_SRCS) \

OBJS = $(DSP_OBJS) $(EFFECTS_OBJS) $(MISC_OBJS) $(PARAMS_OBJS) \
    $(SAMPLES_OBJS) $(SEQ_OBJS) $(SYNTH_OBJS) $(DIRENT_OBJS) \
    $(OUTPUT_OBJS) $(VST_OBJS) $(ZYNWISE_OBJS) \


OUT_DIR = build

zynwise: $(OUT_DIR) $(OBJS) $(RES_OBJ)     
    $(LINK) $(LDFLAGS) $(LIBS) $(OBJS) $(RES_OBJ) /OUT:"$(TARGET)"
    mt /manifest build\ZynWise.dll.intermediate.manifest \
        /outputresource:build\ZynWise.dll;2

$(DSP_OBJS): $(DSP_SRCS)
    $(COMPILE) $(CFLAGS) $(INCLUDES) $(DEFINES) -c Dsp\$(*B).cpp 
   
$(EFFECTS_OBJS): $(EFFECTS_SRCS) 
    $(COMPILE) $(CFLAGS) $(INCLUDES) $(DEFINES) -c Effects\$(*B).cpp
    
$(MISC_OBJS): $(MISC_SRCS)
    $(COMPILE) $(CFLAGS) $(INCLUDES) $(DEFINES) -c Misc\$(*B).cpp
    
$(PARAMS_OBJS): $(PARAMS_SRCS)
    $(COMPILE) $(CFLAGS) $(INCLUDES) $(DEFINES) -c Params\$(*B).cpp
    
$(SAMPLES_OBJS): $(SAMPLES_SRCS)
    $(COMPILE) $(CFLAGS) $(INCLUDES) $(DEFINES) -c Samples\$(*B).cpp
    
$(SEQ_OBJS): $(SEQ_SRCS)
    $(COMPILE) $(CFLAGS) $(INCLUDES) $(DEFINES) -c Seq\$(*B).cpp
    
$(SYNTH_OBJS): $(SYNTH_SRCS)
    $(COMPILE) $(CFLAGS) $(INCLUDES) $(DEFINES) -c Synth\$(*B).cpp
    
$(DIRENT_OBJS): $(DIRENT_SRCS)
    $(COMPILE) $(CFLAGS) $(INCLUDES) $(DEFINES) -c Libs\$(*B).c
    
$(OUTPUT_OBJS): $(OUTPUT_SRCS)
    $(COMPILE) $(CFLAGS) $(INCLUDES) $(DEFINES) -c Output\$(*B).cpp
    
$(VST_OBJS): $(VST_SRCS)
    $(COMPILE) $(CFLAGS) $(INCLUDES) $(DEFINES) -c vstsdk\$(*B).cpp 

$(ZYNWISE_OBJS): $(ZYNWISE_SRCS)
    $(COMPILE) $(CFLAGS) $(INCLUDES) $(DEFINES) -c $(*B).cpp 

$(RES_OBJ): $(RES_SRC)
    rc /fo $(RES_OBJ) $(RES_SRC)

$(OUT_DIR):
	mkdir build