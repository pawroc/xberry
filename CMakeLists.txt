cmake_minimum_required(VERSION 3.16)

project(xberry
    LANGUAGES CXX
    VERSION 0.0.1
    DESCRIPTION "Xberry recruitment task")


#######################
# Set include/find_package search PATH
#
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)


########################
# Compiler settings
#
include(compiler_setup)

########################
# Components
#
set(UTILS_LIB_NAME "${PROJECT_NAME}_utils")
add_library(${UTILS_LIB_NAME} INTERFACE)
target_include_directories(${UTILS_LIB_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/common/inc)

add_subdirectory(controlUnit)
add_subdirectory(sensors)

########################
# Helper functions
#
#include(helper_functions)

if(BUILD_TESTING)
    include(CTest)
    include(googletest)

    enable_testing()

    add_definitions(-DBUILD_TESTING=${BUILD_TESTING})
endif()
