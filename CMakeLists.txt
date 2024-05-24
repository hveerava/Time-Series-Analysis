cmake_minimum_required(VERSION 3.10)
project(TimeSeriesAnalysisLibrary VERSION 1.0)

# C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(BUILD_EXAMPLES "Build examples" ON)
option(BUILD_TESTS "Build tests" ON)

# include dirs
include_directories(include)

# source files
file(GLOB SOURCES "src/*.cpp")

# build lib
add_library(TimeSeriesAnalysisLibrary STATIC ${SOURCES})

# target
install(TARGETS TimeSeriesAnalysisLibrary DESTINATION lib)
install(DIRECTORY include/ DESTINATION include)

# pkg
set(CPACK_PACKAGE_NAME "TimeSeriesAnalysisLibrary")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_GENERATOR "ZIP")
include(CPack)