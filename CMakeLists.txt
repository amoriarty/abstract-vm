cmake_minimum_required(VERSION 3.3)
project(abstract-vm)

set(CMAKE_CXX_COMPILER  "/usr/bin/clang++")
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror")

include_directories(include)

add_executable(abstract-vm
		srcs/main.cpp
		interface/IOperand.hpp
		class/eOperandType.cpp include/eOperandType.hpp)
