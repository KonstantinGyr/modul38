# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\soundButton_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\soundButton_autogen.dir\\ParseCache.txt"
  "soundButton_autogen"
  )
endif()
