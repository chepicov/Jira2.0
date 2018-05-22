cmake_minimum_required(VERSION 3.10)
project(Mark)

set(CMAKE_CXX_STANDARD 11)

add_executable(Mark main.cpp Admin.h AdminMenu.h Employee.h EmployeeMenu.h Exception.h FileService.h User.h Project.h Task.h Login.h Registration.h SHA256.h)