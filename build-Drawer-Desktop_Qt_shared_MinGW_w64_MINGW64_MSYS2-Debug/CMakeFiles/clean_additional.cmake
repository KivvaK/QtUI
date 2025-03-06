# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Drawer_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Drawer_autogen.dir\\ParseCache.txt"
  "Drawer_autogen"
  )
endif()
