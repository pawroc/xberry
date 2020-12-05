cmake_minimum_required(VERSION 3.16)

set(TEST_EXE_NAME "ControlUnit_UT")

set(SOURCES
    testControlUnit.cpp
)

add_executable(${TEST_EXE_NAME} ${SOURCES})
target_link_libraries(${TEST_EXE_NAME} PUBLIC
    gtest
    gmock
    gtest_main
    gmock_main
    xberry_ControlUnit)

set_target_properties(${TEST_EXE_NAME}
    PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
)

add_test(NAME ${TEST_EXE_NAME}
         COMMAND ${TEST_EXE_NAME})
