# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Painting_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Painting_autogen.dir\\ParseCache.txt"
  "Painting_autogen"
  )
endif()
