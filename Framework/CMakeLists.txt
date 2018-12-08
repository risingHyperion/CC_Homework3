# Set paths
set(INCROOT ${PROJECT_SOURCE_DIR}/Framework/include)
set(SRCROOT ${PROJECT_SOURCE_DIR}/Framework/source)
set(BOOST_HOME "C:/boost/boost_1_68_0/")

# Get files
file(GLOB INCS "${INCROOT}/*.h")
file(GLOB SRCS "${SRCROOT}/*.cpp")

# Find boost
find_package(Boost 1.68.0) 

include_directories(${Boost_INCLUDE_DIR})

# Create DLL
add_library(Framework SHARED ${SRCS} ${INCS})