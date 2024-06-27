# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Weather-main004_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Weather-main004_autogen.dir/ParseCache.txt"
  "Weather-main004_autogen"
  )
endif()
