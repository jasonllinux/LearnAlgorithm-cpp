################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ds/queue/queue.cpp 

OBJS += \
./src/ds/queue/queue.o 

CPP_DEPS += \
./src/ds/queue/queue.d 


# Each subdirectory must supply rules for building sources it contributes
src/ds/queue/%.o: ../src/ds/queue/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/rescue01/git/LearnAlgorithm-cpp/LearnAlgorithm/src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


