MAKECMD         = "%MATLAB%\bin\win32\gmake"
HOST            = PC
BUILD           = yes
SYS_TARGET_FILE = raptor.tlc
SHELL           = cmd

MODEL_NAME		= A1_Test
MODULES			= A1_Test_data.c HCU_LIB.c Timer_BGND_G6Wyo.c Timer_ooqlV.c XCP_App.c can_4423__0004.c can_4424__0004.c data.c raptor_app.c raptor_lin_general.c rtGetInf.c rtGetNaN.c rt_nonfinite.c rt_zcfcn.c xcp_protocol.c XCP_App.c.c
NUMST           = 
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS =
NCSTATES =

$(MODEL_NAME).mot: 
	@echo ### Created Makefile ...

DO_NOT_USE_CHECKSUMS = 1

# EOF: raptor.tmf