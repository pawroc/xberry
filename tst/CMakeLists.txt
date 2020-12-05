cmake_minimum_required(VERSION 3.16)

set(TEST_EXECUTABLE_NAME "${PROJECT_NAME}_UT")

set(MOCKS)
set(SOURCES
    testMain.cpp
    testLib.cpp
)

add_executable(${TEST_EXECUTABLE_NAME} ${SOURCES} ${MOCKS})
target_link_libraries(${TEST_EXECUTABLE_NAME} PUBLIC
    gtest
    gmock
    gtest_main
    gmock_main
    ${PROJECT_NAME})

set_target_properties(${PROJECT_NAME}_UT
    PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
)

add_test(NAME ${TEST_EXECUTABLE_NAME}
         COMMAND ${TEST_EXECUTABLE_NAME})
