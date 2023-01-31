# beads
Specialized Utility Modules to perform simple tasks

## logger

A simple logger that categorizes logs like ostream and supports file writing also.

Include Following Lines in CMakeLists.txt

`target_include_directories(<project_name> PUBLIC ${PROJECT_SOURCE_DIR}/logger/logger.h)`

`add_executable(<project_name> logger/logger.cpp)`
