######################### 
# Options
#


######################### 
# Build type
#
set(CMAKE_BUILD_TYPE Debug)

#########################
# Variables
#
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#########################
# Compiler flags
add_compile_options(
    -Wall
    -Wextra
    -pedantic
    -Werror
)
