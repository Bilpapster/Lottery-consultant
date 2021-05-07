# cmake_minimum_required(VERSION <specify CMake version here>)
project(untitled C)

set(CMAKE_C_STANDARD 99)

add_executable(untitled Consultant/main.c "File Handling/fileHandlingFunctions.h" "File Handling/fileHandlingFunctions.c" Utility/macrosDefinition.h Model/metrics.h Model/metrics.c Utility/utilityFunctions.h Utility/utilityFunctions.c Model/requestHandling.h Model/requestHandling.c "Error Handling/errorHandling.h" "Error Handling/errorHandling.c")