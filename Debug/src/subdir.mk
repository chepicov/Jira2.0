################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Admin.cpp \
../src/Employee.cpp \
../src/Jira2.0.cpp \
../src/Project.cpp \
../src/SHA256.cpp \
../src/Task.cpp \
../src/Team.cpp \
../src/User.cpp 

OBJS += \
./src/Admin.o \
./src/Employee.o \
./src/Jira2.0.o \
./src/Project.o \
./src/SHA256.o \
./src/Task.o \
./src/Team.o \
./src/User.o 

CPP_DEPS += \
./src/Admin.d \
./src/Employee.d \
./src/Jira2.0.d \
./src/Project.d \
./src/SHA256.d \
./src/Task.d \
./src/Team.d \
./src/User.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


