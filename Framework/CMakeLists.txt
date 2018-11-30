# Set paths
set(INCROOT ${PROJECT_SOURCE_DIR}/Framework/include)
set(SRCROOT ${PROJECT_SOURCE_DIR}/Framework/source)

# Get files
file(GLOB INCS "${INCROOT}/*.h")
file(GLOB SRCS "${SRCROOT}/*.cpp")

# Create DLL
add_library(Framework SHARED ${SRCS} ${INCS})