# cmake_minimum_required(VERSION <specify CMake version here>)
project(untitled C)

set(CMAKE_C_STANDARD 99)

add_executable(untitled main.c fileHandlingFunctions.h fileHandlingFunctions.c macrosDefinition.h metrics.h metrics.c utilityFunctions.h utilityFunctions.c requestHandling.h requestHandling.c errorHandling.h errorHandling.c)