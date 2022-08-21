# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\soundButton2_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\soundButton2_autogen.dir\\ParseCache.txt"
  "soundButton2_autogen"
  )
endif()
