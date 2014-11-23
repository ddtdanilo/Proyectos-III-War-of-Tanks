################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Generated_Code/ADC.c" \
"../Generated_Code/B_1.c" \
"../Generated_Code/Cpu.c" \
"../Generated_Code/IO_Map.c" \
"../Generated_Code/LED_1.c" \
"../Generated_Code/LED_OUT.c" \
"../Generated_Code/M_1.c" \
"../Generated_Code/M_2.c" \
"../Generated_Code/PE_Timer.c" \
"../Generated_Code/Serial_1.c" \
"../Generated_Code/Serial_2.c" \
"../Generated_Code/Vectors.c" \

C_SRCS += \
../Generated_Code/ADC.c \
../Generated_Code/B_1.c \
../Generated_Code/Cpu.c \
../Generated_Code/IO_Map.c \
../Generated_Code/LED_1.c \
../Generated_Code/LED_OUT.c \
../Generated_Code/M_1.c \
../Generated_Code/M_2.c \
../Generated_Code/PE_Timer.c \
../Generated_Code/Serial_1.c \
../Generated_Code/Serial_2.c \
../Generated_Code/Vectors.c \

OBJS += \
./Generated_Code/ADC_c.obj \
./Generated_Code/B_1_c.obj \
./Generated_Code/Cpu_c.obj \
./Generated_Code/IO_Map_c.obj \
./Generated_Code/LED_1_c.obj \
./Generated_Code/LED_OUT_c.obj \
./Generated_Code/M_1_c.obj \
./Generated_Code/M_2_c.obj \
./Generated_Code/PE_Timer_c.obj \
./Generated_Code/Serial_1_c.obj \
./Generated_Code/Serial_2_c.obj \
./Generated_Code/Vectors_c.obj \

OBJS_QUOTED += \
"./Generated_Code/ADC_c.obj" \
"./Generated_Code/B_1_c.obj" \
"./Generated_Code/Cpu_c.obj" \
"./Generated_Code/IO_Map_c.obj" \
"./Generated_Code/LED_1_c.obj" \
"./Generated_Code/LED_OUT_c.obj" \
"./Generated_Code/M_1_c.obj" \
"./Generated_Code/M_2_c.obj" \
"./Generated_Code/PE_Timer_c.obj" \
"./Generated_Code/Serial_1_c.obj" \
"./Generated_Code/Serial_2_c.obj" \
"./Generated_Code/Vectors_c.obj" \

C_DEPS += \
./Generated_Code/ADC_c.d \
./Generated_Code/B_1_c.d \
./Generated_Code/Cpu_c.d \
./Generated_Code/IO_Map_c.d \
./Generated_Code/LED_1_c.d \
./Generated_Code/LED_OUT_c.d \
./Generated_Code/M_1_c.d \
./Generated_Code/M_2_c.d \
./Generated_Code/PE_Timer_c.d \
./Generated_Code/Serial_1_c.d \
./Generated_Code/Serial_2_c.d \
./Generated_Code/Vectors_c.d \

C_DEPS_QUOTED += \
"./Generated_Code/ADC_c.d" \
"./Generated_Code/B_1_c.d" \
"./Generated_Code/Cpu_c.d" \
"./Generated_Code/IO_Map_c.d" \
"./Generated_Code/LED_1_c.d" \
"./Generated_Code/LED_OUT_c.d" \
"./Generated_Code/M_1_c.d" \
"./Generated_Code/M_2_c.d" \
"./Generated_Code/PE_Timer_c.d" \
"./Generated_Code/Serial_1_c.d" \
"./Generated_Code/Serial_2_c.d" \
"./Generated_Code/Vectors_c.d" \

OBJS_OS_FORMAT += \
./Generated_Code/ADC_c.obj \
./Generated_Code/B_1_c.obj \
./Generated_Code/Cpu_c.obj \
./Generated_Code/IO_Map_c.obj \
./Generated_Code/LED_1_c.obj \
./Generated_Code/LED_OUT_c.obj \
./Generated_Code/M_1_c.obj \
./Generated_Code/M_2_c.obj \
./Generated_Code/PE_Timer_c.obj \
./Generated_Code/Serial_1_c.obj \
./Generated_Code/Serial_2_c.obj \
./Generated_Code/Vectors_c.obj \


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/ADC_c.obj: ../Generated_Code/ADC.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Generated_Code/ADC.args" -ObjN="Generated_Code/ADC_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/%.d: ../Generated_Code/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Generated_Code/B_1_c.obj: ../Generated_Code/B_1.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Generated_Code/B_1.args" -ObjN="Generated_Code/B_1_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/Cpu_c.obj: ../Generated_Code/Cpu.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Generated_Code/Cpu.args" -ObjN="Generated_Code/Cpu_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/IO_Map_c.obj: ../Generated_Code/IO_Map.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Generated_Code/IO_Map.args" -ObjN="Generated_Code/IO_Map_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/LED_1_c.obj: ../Generated_Code/LED_1.c
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Generated_Code/LED_1.args" -ObjN="Generated_Code/LED_1_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/LED_OUT_c.obj: ../Generated_Code/LED_OUT.c
	@echo 'Building file: $<'
	@echo 'Executing target #10 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Generated_Code/LED_OUT.args" -ObjN="Generated_Code/LED_OUT_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/M_1_c.obj: ../Generated_Code/M_1.c
	@echo 'Building file: $<'
	@echo 'Executing target #11 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Generated_Code/M_1.args" -ObjN="Generated_Code/M_1_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/M_2_c.obj: ../Generated_Code/M_2.c
	@echo 'Building file: $<'
	@echo 'Executing target #12 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Generated_Code/M_2.args" -ObjN="Generated_Code/M_2_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/PE_Timer_c.obj: ../Generated_Code/PE_Timer.c
	@echo 'Building file: $<'
	@echo 'Executing target #13 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Generated_Code/PE_Timer.args" -ObjN="Generated_Code/PE_Timer_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/Serial_1_c.obj: ../Generated_Code/Serial_1.c
	@echo 'Building file: $<'
	@echo 'Executing target #14 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Generated_Code/Serial_1.args" -ObjN="Generated_Code/Serial_1_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/Serial_2_c.obj: ../Generated_Code/Serial_2.c
	@echo 'Building file: $<'
	@echo 'Executing target #15 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Generated_Code/Serial_2.args" -ObjN="Generated_Code/Serial_2_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/Vectors_c.obj: ../Generated_Code/Vectors.c
	@echo 'Building file: $<'
	@echo 'Executing target #16 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Generated_Code/Vectors.args" -ObjN="Generated_Code/Vectors_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '


