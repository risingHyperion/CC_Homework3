# Application name
set(APP_NAME "Framwork")

# Set Boost environment
set(BOOST_ROOT "C:/boost/boost_1_68_0/")
set(Boost_USE_STATIC_LIBS ON) 
set(Boost_USE_MULTITHREADED ON)

# Log message for debugging
message(STATUS "*** Parsing ${APP_NAME} ***")

# Try to find boost
find_package(Boost 1.68.0 COMPONENTS system REQUIRED)

# Check if found
if(Boost_FOUND)
	message(STATUS "Boost was found")
	message(STATUS "Trying to add include directories, the used variable is ${Boost_INCLUDE_DIR}")
	
	include_directories (${Boost_INCLUDE_DIR})
else()
	message(FATAL_ERROR "Boost library has not been found. Exiting...")
endif()

# Set paths to files
set(INCROOT ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SRCROOT ${CMAKE_CURRENT_SOURCE_DIR}/source)

# Get the files
file(GLOB INCS "${INCROOT}/*.h")
file(GLOB SRCS "${SRCROOT}/*.cpp")

# Create Executable
add_executable(${APP_NAME} ${SRCS} ${INCS})

# We are using C++
set_target_properties(${APP_NAME} PROPERTIES LINKER_LANGUAGE CXX)