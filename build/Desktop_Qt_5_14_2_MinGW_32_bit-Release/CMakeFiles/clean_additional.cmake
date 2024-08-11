# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\Morse-code-tools_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Morse-code-tools_autogen.dir\\ParseCache.txt"
  "Morse-code-tools_autogen"
  )
endif()
