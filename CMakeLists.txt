cmake_minimum_required(VERSION 3.10)

set(BT_MAXTHREADS 8 CACHE STRING "Maximum number of created threads")

project(BalancedThreads VERSION 0.1)

add_subdirectory(src)

target_include_directories (${PROJECT_NAME} PUBLIC build/src)

