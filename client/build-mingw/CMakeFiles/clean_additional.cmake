# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "apps\\client-desktop\\CMakeFiles\\client-desktop_autogen.dir\\AutogenUsed.txt"
  "apps\\client-desktop\\CMakeFiles\\client-desktop_autogen.dir\\ParseCache.txt"
  "apps\\client-desktop\\client-desktop_autogen"
  "libs\\network\\CMakeFiles\\network_autogen.dir\\AutogenUsed.txt"
  "libs\\network\\CMakeFiles\\network_autogen.dir\\ParseCache.txt"
  "libs\\network\\network_autogen"
  "libs\\ui\\CMakeFiles\\ui_autogen.dir\\AutogenUsed.txt"
  "libs\\ui\\CMakeFiles\\ui_autogen.dir\\ParseCache.txt"
  "libs\\ui\\ui_autogen"
  "plugins\\chat\\CMakeFiles\\chat_autogen.dir\\AutogenUsed.txt"
  "plugins\\chat\\CMakeFiles\\chat_autogen.dir\\ParseCache.txt"
  "plugins\\chat\\chat_autogen"
  "tests\\integration\\CMakeFiles\\tst_login_flow_autogen.dir\\AutogenUsed.txt"
  "tests\\integration\\CMakeFiles\\tst_login_flow_autogen.dir\\ParseCache.txt"
  "tests\\integration\\tst_login_flow_autogen"
  "tests\\unit\\CMakeFiles\\tst_core_autogen.dir\\AutogenUsed.txt"
  "tests\\unit\\CMakeFiles\\tst_core_autogen.dir\\ParseCache.txt"
  "tests\\unit\\CMakeFiles\\tst_stores_autogen.dir\\AutogenUsed.txt"
  "tests\\unit\\CMakeFiles\\tst_stores_autogen.dir\\ParseCache.txt"
  "tests\\unit\\tst_core_autogen"
  "tests\\unit\\tst_stores_autogen"
  )
endif()
