cmake_minimum_required(VERSION 3.16)

project(sbl_position LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 算法切换。也可在包含 sbl/config.hpp 之前自行定义 SBL_POSITION_ALGO。
#   1  经典三角定位
#   2  双基准站斜距 + 已知移动站高度
set(SBL_POSITION_ALGO 1 CACHE STRING
    "Positioning algorithm: 1 triangulation, 2 slant range with known height")
set_property(CACHE SBL_POSITION_ALGO PROPERTY STRINGS 1 2)

if(NOT SBL_POSITION_ALGO MATCHES "^[12]$")
    message(FATAL_ERROR "SBL_POSITION_ALGO must be 1 or 2")
endif()

add_library(sbl_position
    src/types.cpp
    src/triangulation.cpp
    src/slant_range.cpp
    src/request.cpp
    src/uncertainty.cpp
    src/mqtt_source.cpp
)
target_include_directories(sbl_position PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    /usr/include/jsoncpp
)
target_link_libraries(sbl_position PUBLIC jsoncpp)
target_compile_definitions(sbl_position PUBLIC SBL_POSITION_ALGO=${SBL_POSITION_ALGO})

add_executable(sbl_position_demo src/main.cpp)
target_link_libraries(sbl_position_demo PRIVATE sbl_position)

add_executable(sbl_range_check tools/range_check.cpp)
