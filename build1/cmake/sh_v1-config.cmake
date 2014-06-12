# sh_V1 CMake config file
#
# This file sets the following variables:
# sh_V1_FOUND - Always TRUE.
# sh_V1_INCLUDE_DIRS - Directories containing the sh_V1 include files.
# sh_V1_IDL_DIRS - Directories containing the sh_V1 IDL files.
# sh_V1_LIBRARIES - Libraries needed to use sh_V1.
# sh_V1_DEFINITIONS - Compiler flags for sh_V1.
# sh_V1_VERSION - The version of sh_V1 found.
# sh_V1_VERSION_MAJOR - The major version of sh_V1 found.
# sh_V1_VERSION_MINOR - The minor version of sh_V1 found.
# sh_V1_VERSION_REVISION - The revision version of sh_V1 found.
# sh_V1_VERSION_CANDIDATE - The candidate version of sh_V1 found.

message(STATUS "Found sh_V1-1.0.0")
set(sh_V1_FOUND TRUE)

find_package(<dependency> REQUIRED)

#set(sh_V1_INCLUDE_DIRS
#    "C:/Program Files/sh_V1/include/sh_v1-1"
#    ${<dependency>_INCLUDE_DIRS}
#    )
#
#set(sh_V1_IDL_DIRS
#    "C:/Program Files/sh_V1/include/sh_v1-1/idl")
set(sh_V1_INCLUDE_DIRS
    "C:/Program Files/sh_V1/include/"
    ${<dependency>_INCLUDE_DIRS}
    )
set(sh_V1_IDL_DIRS
    "C:/Program Files/sh_V1/include//idl")


if(WIN32)
    set(sh_V1_LIBRARIES
        "C:/Program Files/sh_V1/components/lib/sh_v1.lib"
        ${<dependency>_LIBRARIES}
        )
else(WIN32)
    set(sh_V1_LIBRARIES
        "C:/Program Files/sh_V1/components/lib/sh_v1.dll"
        ${<dependency>_LIBRARIES}
        )
endif(WIN32)

set(sh_V1_DEFINITIONS ${<dependency>_DEFINITIONS})

set(sh_V1_VERSION 1.0.0)
set(sh_V1_VERSION_MAJOR 1)
set(sh_V1_VERSION_MINOR 0)
set(sh_V1_VERSION_REVISION 0)
set(sh_V1_VERSION_CANDIDATE )

