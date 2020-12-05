if(BUILD_TESTING)
    include(CTest)
    include(googletest)

    enable_testing()

    add_definitions(-DBUILD_TESTING=${BUILD_TESTING})
    add_subdirectory(tst)
endif()
