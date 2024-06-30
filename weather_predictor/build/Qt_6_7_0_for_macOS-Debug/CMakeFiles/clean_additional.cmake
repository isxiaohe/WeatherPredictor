# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Weather_Predictor_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Weather_Predictor_autogen.dir/ParseCache.txt"
  "Weather_Predictor_autogen"
  )
endif()
