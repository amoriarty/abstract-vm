cmake_minimum_required(VERSION 3.3)
project(abstract-vm)

set(CMAKE_CXX_COMPILER  "/usr/bin/clang++")
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror")

include_directories(include)
include_directories(include/class)
include_directories(include/interface)
include_directories(include/template)

add_executable(abstract-vm
		srcs/main.cpp
		include/template/Operand.tpp
		srcs/class/Factory.cpp
		srcs/class/Exceptions.cpp
		srcs/class/Parser.cpp
		srcs/class/Calculator.cpp)
