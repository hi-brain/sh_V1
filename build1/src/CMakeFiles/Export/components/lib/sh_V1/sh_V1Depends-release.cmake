#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "sh_V1" for configuration "Release"
set_property(TARGET sh_V1 APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(sh_V1 PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/components/lib/sh_V1.lib"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "RTC110;coil110;omniORB416_rt;omniDynamic416_rt;omnithread34_rt;advapi32;ws2_32;mswsock;mclmcrrt.lib;shV1.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/components/bin/sh_V1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS sh_V1 )
list(APPEND _IMPORT_CHECK_FILES_FOR_sh_V1 "${_IMPORT_PREFIX}/components/lib/sh_V1.lib" "${_IMPORT_PREFIX}/components/bin/sh_V1.dll" )

# Import target "sh_V1Comp" for configuration "Release"
set_property(TARGET sh_V1Comp APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(sh_V1Comp PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/components/bin/sh_V1Comp.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS sh_V1Comp )
list(APPEND _IMPORT_CHECK_FILES_FOR_sh_V1Comp "${_IMPORT_PREFIX}/components/bin/sh_V1Comp.exe" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
