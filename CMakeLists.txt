cmake_minimum_required(VERSION 3.3)
project(abstract-vm)

set(CMAKE_CXX_COMPILER  "/usr/bin/clang++")
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror")

add_executable(abstract-vm
		srcs/main.cpp)
