####################################################
# GEANT4 binary plugin example 
#
# File:      CMakeLists.txt
#
# Author:    Christopher M Poole,
# Email:     mail@christopherpoole.net
#
# Date:      31st December, 2011
####################################################

cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
project(GEANT4_PLUGIN)

# GEANT4 core
find_package(Geant4 REQUIRED ui_all vis_all)
include(${Geant4_USE_FILE})
include_directories(${PROJECT_SOURCE_DIR}/include)

# User code
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)

add_executable(plugin_example plugin_example.cc ${sources} ${headers})
target_link_libraries(plugin_example ${Geant4_LIBRARIES})

