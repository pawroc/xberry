cmake_minimum_required(VERSION 3.16)

set(LIB_NAME "xberry_ControlUnit")
set(EXE_NAME ${LIB_NAME}_exe)
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(SOURCES
    ${SRC_DIR}/controlUnit.cpp
)


add_library(${LIB_NAME} ${SOURCES})
target_link_libraries(${LIB_NAME} PUBLIC ${UTILS_LIB_NAME})
target_include_directories(${LIB_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)
set_target_properties(${LIB_NAME}
    PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
)

add_executable(${EXE_NAME} ${SRC_DIR}/main.cpp)
target_link_libraries(${EXE_NAME} PUBLIC ${LIB_NAME})
target_include_directories(${EXE_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/inc)
set_target_properties(${EXE_NAME}
    PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
)


########################
# Unit Tests
#
#include(unit_tests)

if(BUILD_TESTING)
    add_subdirectory(tst)
endif()
