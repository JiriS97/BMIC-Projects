################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/mainB.c" \

C_SRCS += \
../Sources/mainB.c \

OBJS += \
./Sources/mainB_c.obj \

OBJS_QUOTED += \
"./Sources/mainB_c.obj" \

C_DEPS += \
./Sources/mainB_c.d \

C_DEPS_QUOTED += \
"./Sources/mainB_c.d" \

OBJS_OS_FORMAT += \
./Sources/mainB_c.obj \


# Each subdirectory must supply rules for building sources it contributes
Sources/mainB_c.obj: ../Sources/mainB.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/mainB.args" -ObjN="Sources/mainB_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/%.d: ../Sources/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '


