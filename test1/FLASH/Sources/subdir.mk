################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
ASM_SRCS += \
../Sources/main.asm \

ASM_SRCS_QUOTED += \
"../Sources/main.asm" \

OBJS += \
./Sources/main_asm.obj \

ASM_DEPS_QUOTED += \
"./Sources/main_asm.d" \

ASM_DEPS += \
./Sources/main_asm.d \

OBJS_QUOTED += \
"./Sources/main_asm.obj" \

OBJS_OS_FORMAT += \
./Sources/main_asm.obj \


# Each subdirectory must supply rules for building sources it contributes
Sources/main_asm.obj: ../Sources/main.asm
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: HCS08 Assembler'
	"$(HC08ToolsEnv)/ahc08" -ArgFile"Sources/main.args" -Objn"Sources/main_asm.obj" "$<" $(ASM_SRCS_QUOTED) -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/main_asm.obj: Sources/main_asm.obj

Sources/%.d: ../Sources/%.asm
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '


