# Application name
set(APP_NAME "Server")

# Set Boost environment
set(BOOST_ROOT "C:/boost/boost_1_68_0/")
set(Boost_USE_STATIC_LIBS ON) 
set(Boost_USE_MULTITHREADED ON)

# Log message for debugging
message(STATUS "*** Parsing ${APP_NAME} ***")

# Try to find boost
find_package(Boost 1.68.0 COMPONENTS system REQUIRED date_time REQUIRED)

# Check if found
if(Boost_FOUND)
	message(STATUS "Boost was found")
	message(STATUS "Trying to add include directories, the used variable is ${Boost_INCLUDE_DIR}")
	
	# Set paths
	set(INCROOT ${CMAKE_CURRENT_SOURCE_DIR}/include)
	set(SRCROOT ${CMAKE_CURRENT_SOURCE_DIR}/source)
	
	include_directories (${INCROOT} ${Boost_INCLUDE_DIR})

	# Get files
	file(GLOB INCS "${INCROOT}/*.h")
	file(GLOB SRCS "${SRCROOT}/*.cpp")

	# Create Executable
	add_executable(${APP_NAME} ${INCS} ${SRCS})
	
	# Path to Framewrok
	link_directories(${PROJECT_SOURCE_DIR}/build/lib)

	# Link dependencies to current application
	target_link_libraries(${APP_NAME} ${Boost_LIBRARIES} Framework)
else()
	message(FATAL_ERROR "Boost library has not been found. Exiting...")
endif()

# We are using C++
set_target_properties(${APP_NAME} PROPERTIES LINKER_LANGUAGE CXX)

# Path to exe
set_target_properties(${APP_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build/exe")

