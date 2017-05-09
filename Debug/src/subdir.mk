################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/DisplayImage.cpp \
../src/Image2Gray.cpp \
../src/ImagePixel.cpp \
../src/OpenWebcam.cpp 

OBJS += \
./src/DisplayImage.o \
./src/Image2Gray.o \
./src/ImagePixel.o \
./src/OpenWebcam.o 

CPP_DEPS += \
./src/DisplayImage.d \
./src/Image2Gray.d \
./src/ImagePixel.d \
./src/OpenWebcam.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/opencv -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


