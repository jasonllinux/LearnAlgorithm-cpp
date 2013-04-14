################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/string/string_fun.cpp \
../src/string/string_match.cpp 

OBJS += \
./src/string/string_fun.o \
./src/string/string_match.o 

CPP_DEPS += \
./src/string/string_fun.d \
./src/string/string_match.d 


# Each subdirectory must supply rules for building sources it contributes
src/string/%.o: ../src/string/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/rescue01/git/LearnAlgorithm-cpp/LearnAlgorithm/src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


