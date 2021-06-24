cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
set(EXECNAME "alu_tb")
project(alu_tb VERSION 0.1.0 LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(universal
  GIT_REPOSITORY  https://github.com/stillwater-sc/universal.git
  GIT_TAG         main
  )
FetchContent_MakeAvailable(universal)


execute_process(
    COMMAND "yes" |  sandpiper-saas -i ${CMAKE_CURRENT_SOURCE_DIR}/src//hw/alu.tlv -o alu.sv --default_includes)
  
find_package(verilator HINTS $ENV{VERILATOR_ROOT})

add_executable(alu_tb src/tb/alu_tb.cpp)
include_directories(src/tb/includes)
include_directories(${universal_SOURCE_DIR}/include/)
#add_dependencies(alu_tb sandpiper)
verilate(alu_tb 
    SOURCES
        ${CMAKE_CURRENT_BINARY_DIR}/alu.sv
        ${CMAKE_CURRENT_BINARY_DIR}/alu_gen.sv
    INCLUDE_DIRS
        ${CMAKE_CURRENT_BINARY_DIR}/includes
        ${CMAKE_CURRENT_BINARY_DIR}/includes/proj_default)
