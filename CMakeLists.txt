cmake_minimum_required(VERSION 3.16)
project(CPTS_223_MA4)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

cmake_minimum_required(VERSION 3.16)
project(CPTS_223_MA4)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

# Explicitly specify OpenMP paths for CLion
include_directories("/opt/homebrew/opt/libomp/include")
link_directories("/opt/homebrew/opt/libomp/lib")

# Add OpenMP compile and link flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Xpreprocessor -fopenmp")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lomp")

add_executable(MA4 main.cpp)
target_link_libraries(MA4 PUBLIC omp)
