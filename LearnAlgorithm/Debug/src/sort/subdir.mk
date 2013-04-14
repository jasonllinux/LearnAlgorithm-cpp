################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/sort/bubbleSort.cpp \
../src/sort/heapSort.cpp \
../src/sort/insertSort.cpp \
../src/sort/mergeSort.cpp \
../src/sort/quickSort.cpp \
../src/sort/selectSort.cpp 

OBJS += \
./src/sort/bubbleSort.o \
./src/sort/heapSort.o \
./src/sort/insertSort.o \
./src/sort/mergeSort.o \
./src/sort/quickSort.o \
./src/sort/selectSort.o 

CPP_DEPS += \
./src/sort/bubbleSort.d \
./src/sort/heapSort.d \
./src/sort/insertSort.d \
./src/sort/mergeSort.d \
./src/sort/quickSort.d \
./src/sort/selectSort.d 


# Each subdirectory must supply rules for building sources it contributes
src/sort/%.o: ../src/sort/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/rescue01/git/LearnAlgorithm-cpp/LearnAlgorithm/src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


