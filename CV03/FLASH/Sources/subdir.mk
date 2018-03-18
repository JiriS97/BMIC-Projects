################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
ASM_SRCS += \
../Sources/mainCompare.asm \

ASM_SRCS_QUOTED += \
"../Sources/mainCompare.asm" \

OBJS += \
./Sources/mainCompare_asm.obj \

ASM_DEPS_QUOTED += \
"./Sources/mainCompare_asm.d" \

ASM_DEPS += \
./Sources/mainCompare_asm.d \

OBJS_QUOTED += \
"./Sources/mainCompare_asm.obj" \

OBJS_OS_FORMAT += \
./Sources/mainCompare_asm.obj \


# Each subdirectory must supply rules for building sources it contributes
Sources/mainCompare_asm.obj: ../Sources/mainCompare.asm
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: HCS08 Assembler'
	"$(HC08ToolsEnv)/ahc08" -ArgFile"Sources/mainCompare.args" -Objn"Sources/mainCompare_asm.obj" "$<" $(ASM_SRCS_QUOTED) -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/mainCompare_asm.obj: Sources/mainCompare_asm.obj

Sources/%.d: ../Sources/%.asm
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '


