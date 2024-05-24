cmake_minimum_required(VERSION 3.10)
project(TimeSeriesAnalysisLibrary VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Options
option(BUILD_EXAMPLES "Build examples" ON)
option(BUILD_TESTS "Build tests" ON)

# Add include directories
include_directories(include)

# Add source files
file(GLOB SOURCES "src/*.cpp")

# Build library
add_library(TimeSeriesAnalysisLibrary STATIC ${SOURCES})

# External dependencies (e.g., if using Boost for some functionality)
# find_package(Boost REQUIRED)
# include_directories(${Boost_INCLUDE_DIRS})
# target_link_libraries(TimeSeriesAnalysisLibrary ${Boost_LIBRARIES})

# Build examples
if(BUILD_EXAMPLES)
    add_executable(example1 examples/example1.cpp)
    target_link_libraries(example1 TimeSeriesAnalysisLibrary)
    # Repeat for other examples if needed
endif()

# Build tests
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

# Install targets (optional)
install(TARGETS TimeSeriesAnalysisLibrary DESTINATION lib)
install(DIRECTORY include/ DESTINATION include)

# Packaging (optional)
set(CPACK_PACKAGE_NAME "TimeSeriesAnalysisLibrary")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_GENERATOR "ZIP")
include(CPack)