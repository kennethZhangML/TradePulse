cmake_minimum_required(VERSION 3.10)

project(TradePulse)

set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(include /usr/local/include/quickfix)

# Source files
file(GLOB SOURCES "src/*.cpp")

# Add executable
add_executable(tradepulse ${SOURCES})

# Link libraries
find_package(Boost REQUIRED COMPONENTS system)
find_package(ZeroMQ REQUIRED)
find_package(TBB REQUIRED)

# Manually specify QuickFIX since it's not a standard package
find_library(QUICKFIX_LIBRARY quickfix /usr/local/lib)

target_link_libraries(tradepulse ${Boost_LIBRARIES} ${ZeroMQ_LIBRARIES} ${TBB_LIBRARIES} ${QUICKFIX_LIBRARY})

