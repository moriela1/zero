# Copyright dywoq 2026
#
# This code is published under Apache License 2.0
# - http://www.apache.org/licenses/LICENSE-2.0
#
# The project repository:
# - https://github.com/dywoq/zero

cmake_minimum_required(VERSION 4.2.3)
project(zero_sys LANGUAGES C ASM)

file(GLOB_RECURSE C_SOURCES
    src/*.c
    src/**/*.c
    src/${CMAKE_SYSTEM_NAME}/${CMAKE_SYSTEM_PROCESSOR}/*.c
    src/${CMAKE_SYSTEM_NAME}/${CMAKE_SYSTEM_PROCESSOR}/**/*.c
)
file(GLOB_RECURSE ASM_SOURCES
    src/*.s 
    src/**/*.s
    src/${CMAKE_SYSTEM_NAME}/${CMAKE_SYSTEM_PROCESSOR}/*.s
    src/${CMAKE_SYSTEM_NAME}/${CMAKE_SYSTEM_PROCESSOR}/**/*.s
)

add_library(${PROJECT_NAME} STATIC ${C_SOURCES} ${ASM_SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC include/)
target_compile_options(${PROJECT_NAME} PRIVATE --std=c23)
