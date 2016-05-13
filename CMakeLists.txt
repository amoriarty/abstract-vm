cmake_minimum_required(VERSION 3.3)
project(abstract-vm)

set(CMAKE_CXX_COMPILER  "/usr/bin/clang++")
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror")

include_directories(include)
include_directories(interface)
include_directories(template)

add_executable(abstract-vm
		srcs/main.cpp
		class/eOperandType.cpp)
