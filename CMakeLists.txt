# Minimum version
cmake_minimum_required (VERSION 3.11)

# Set project name
project (Boilerplate)

# Subdirectories
add_subdirectory(Application)
add_subdirectory(Framework)

# Set as startup project
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Application)