# Application name
set(APP_NAME "Client")

# Log message for debugging
message(STATUS "*** Parsing ${APP_NAME} ***")

# Set paths
set(INCROOT ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SRCROOT ${CMAKE_CURRENT_SOURCE_DIR}/source)

# Get files
file(GLOB INCS "${INCROOT}/*.h")
file(GLOB SRCS "${SRCROOT}/*.cpp")

# Create Executable
add_executable(${APP_NAME} ${SRCS} ${INCS})

# Link with Framework
#target_link_libraries(${APP_NAME} Framework)

# We are using C++
set_target_properties(${APP_NAME} PROPERTIES LINKER_LANGUAGE CXX)