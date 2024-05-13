# cmake version
cmake_minimum_required(VERSION 3.1.6)

# project name
project(hello)

# src list
set(SRC_LIST "hello.cpp")

# out path
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/bin)

# target
add_executable(${PROJECT_NAME} ${SRC_LIST})

# -I
target_include_directories(${PROJECT_NAME} PUBLIC)

# -L
target_link_directories(${PROJECT_NAME} PUBLIC)

# -l
target_link_libraries(${PROJECT_NAME} )