# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles/inventory_app_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/inventory_app_autogen.dir/ParseCache.txt"
  "inventory_app_autogen"
  )
endif()