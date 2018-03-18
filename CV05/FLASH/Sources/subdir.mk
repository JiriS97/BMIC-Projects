################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
ASM_SRCS += \
../Sources/mainB.asm \

ASM_SRCS_QUOTED += \
"../Sources/mainB.asm" \

OBJS += \
./Sources/mainB_asm.obj \

ASM_DEPS_QUOTED += \
"./Sources/mainB_asm.d" \

ASM_DEPS += \
./Sources/mainB_asm.d \

OBJS_QUOTED += \
"./Sources/mainB_asm.obj" \

OBJS_OS_FORMAT += \
./Sources/mainB_asm.obj \


# Each subdirectory must supply rules for building sources it contributes
Sources/mainB_asm.obj: ../Sources/mainB.asm
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: HCS08 Assembler'
	"$(HC08ToolsEnv)/ahc08" -ArgFile"Sources/mainB.args" -Objn"Sources/mainB_asm.obj" "$<" $(ASM_SRCS_QUOTED) -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/mainB_asm.obj: Sources/mainB_asm.obj

Sources/%.d: ../Sources/%.asm
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '


