cmake_minimum_required(VERSION 3.20)
project(asaphus_interview_task LANGUAGES CXX)

set(AGAME_MECH_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/src)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tests)

enable_testing()
