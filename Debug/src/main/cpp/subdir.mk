################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/main/cpp/Matrix.cpp \
../src/main/cpp/main.cpp 

OBJS += \
./src/main/cpp/Matrix.o \
./src/main/cpp/main.o 

CPP_DEPS += \
./src/main/cpp/Matrix.d \
./src/main/cpp/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/main/cpp/%.o: ../src/main/cpp/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


