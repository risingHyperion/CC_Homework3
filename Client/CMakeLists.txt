# Set paths
set(INCROOT ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SRCROOT ${CMAKE_CURRENT_SOURCE_DIR}/source)

# Get files
file(GLOB INCS "${INCROOT}/*.h")
file(GLOB SRCS "${SRCROOT}/*.cpp")

# Create Executable
add_executable(Client ${SRCS} ${INCS})

# Link with Framework
#target_link_libraries(Client Framework)

# We are using C++
set_target_properties(Client PROPERTIES LINKER_LANGUAGE CXX)