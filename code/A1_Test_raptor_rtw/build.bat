@echo off
set PATH=%PATH%;C:\NXP\S32DS_Power_v2.1\S32DS\build_tools\powerpc-eabivle-4_9\bin;C:\Program Files (x86)\NewEagle\Raptor\2021b_2.0.14465\build;C:\Program Files (x86)\NewEagle\Raptor\2021b_2.0.14465\GCM-5743R\lib
set LDFILES=objs\A1_Test.o objs\A1_Test_data.o objs\HCU_LIB.o objs\Timer_BGND_G6Wyo.o objs\Timer_ooqlV.o objs\XCP_App.o objs\can_4423__0004.o objs\can_4424__0004.o objs\data.o objs\raptor_app.o objs\raptor_lin_general.o objs\rtGetInf.o objs\rtGetNaN.o objs\rt_nonfinite.o objs\rt_zcfcn.o objs\xcp_protocol.o 
@if exist .\objs rmdir /Q /S .\objs > NUL
@mkdir .\objs > NUL
set PATH=%PATH%;C:\NXP\S32DS_Power_v2.1\S32DS\build_tools\powerpc-eabivle-4_9\bin
echo powerpc-eabivle-gcc "@compiler.args" -o "./objs/A1_Test.o" A1_Test.c 
powerpc-eabivle-gcc "@compiler.args" -o "./objs/A1_Test.o" A1_Test.c 
echo powerpc-eabivle-gcc "@compiler.args" -o "./objs/A1_Test_data.o" A1_Test_data.c 
powerpc-eabivle-gcc "@compiler.args" -o "./objs/A1_Test_data.o" A1_Test_data.c 
echo powerpc-eabivle-gcc "@compiler.args" -o "./objs/HCU_LIB.o" HCU_LIB.c 
powerpc-eabivle-gcc "@compiler.args" -o "./objs/HCU_LIB.o" HCU_LIB.c 
echo powerpc-eabivle-gcc "@compiler.args" -o "./objs/Timer_BGND_G6Wyo.o" Timer_BGND_G6Wyo.c 
powerpc-eabivle-gcc "@compiler.args" -o "./objs/Timer_BGND_G6Wyo.o" Timer_BGND_G6Wyo.c 
echo powerpc-eabivle-gcc "@compiler.args" -o "./objs/Timer_ooqlV.o" Timer_ooqlV.c 
powerpc-eabivle-gcc "@compiler.args" -o "./objs/Timer_ooqlV.o" Timer_ooqlV.c 
echo powerpc-eabivle-gcc "@compiler.args" -o "./objs/XCP_App.o" XCP_App.c 
powerpc-eabivle-gcc "@compiler.args" -o "./objs/XCP_App.o" XCP_App.c 
echo powerpc-eabivle-gcc "@compiler.args" -o "./objs/can_4423__0004.o" can_4423__0004.c 
powerpc-eabivle-gcc "@compiler.args" -o "./objs/can_4423__0004.o" can_4423__0004.c 
echo powerpc-eabivle-gcc "@compiler.args" -o "./objs/can_4424__0004.o" can_4424__0004.c 
powerpc-eabivle-gcc "@compiler.args" -o "./objs/can_4424__0004.o" can_4424__0004.c 
echo powerpc-eabivle-gcc "@compiler.args" -o "./objs/data.o" data.c 
powerpc-eabivle-gcc "@compiler.args" -o "./objs/data.o" data.c 
echo powerpc-eabivle-gcc "@compiler.args" -o "./objs/raptor_app.o" raptor_app.c 
powerpc-eabivle-gcc "@compiler.args" -o "./objs/raptor_app.o" raptor_app.c 
echo powerpc-eabivle-gcc "@compiler.args" -o "./objs/raptor_lin_general.o" raptor_lin_general.c 
powerpc-eabivle-gcc "@compiler.args" -o "./objs/raptor_lin_general.o" raptor_lin_general.c 
echo powerpc-eabivle-gcc "@compiler.args" -o "./objs/rtGetInf.o" rtGetInf.c 
powerpc-eabivle-gcc "@compiler.args" -o "./objs/rtGetInf.o" rtGetInf.c 
echo powerpc-eabivle-gcc "@compiler.args" -o "./objs/rtGetNaN.o" rtGetNaN.c 
powerpc-eabivle-gcc "@compiler.args" -o "./objs/rtGetNaN.o" rtGetNaN.c 
echo powerpc-eabivle-gcc "@compiler.args" -o "./objs/rt_nonfinite.o" rt_nonfinite.c 
powerpc-eabivle-gcc "@compiler.args" -o "./objs/rt_nonfinite.o" rt_nonfinite.c 
echo powerpc-eabivle-gcc "@compiler.args" -o "./objs/rt_zcfcn.o" rt_zcfcn.c 
powerpc-eabivle-gcc "@compiler.args" -o "./objs/rt_zcfcn.o" rt_zcfcn.c 
echo powerpc-eabivle-gcc "@compiler.args" -o "./objs/xcp_protocol.o" xcp_protocol.c 
powerpc-eabivle-gcc "@compiler.args" -o "./objs/xcp_protocol.o" xcp_protocol.c 
if %ERRORLEVEL% NEQ 0 exit /B %ERRORLEVEL%
echo Linking A1_Test ...
powerpc-eabivle-gcc -o A1_Test.elf "@hw_linker.args"
if %ERRORLEVEL% NEQ 0 exit /B %ERRORLEVEL%
powerpc-eabivle-objcopy -I elf32-powerpc -O ihex A1_Test.elf A1_Test.hex
powerpc-eabivle-nm -a A1_Test.elf > A1_Test.sym
echo Copy : A1_Test.hex 
copy A1_Test.hex "H:\§Úªº¶³ºÝµwºÐ\110448005\TJA\code\A1_Test_raptor_rtw\A1_Test_083.hex" /Y
