cmake_minimum_required(VERSION 3.16)

project(sbl_position LANGUAGES C CXX)

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
    src/base_id.cpp
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

# ahrs_9d_eskf 自带的 CMakeLists 指向代码生成时的目录，这里不使用。
# 编入库内除 examples、html、interface 以外的 C 源文件。interface 是 MATLAB mex 网关。
file(GLOB_RECURSE AHRS_9D_ESKF_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/ahrs_9d_eskf/*.c")
list(FILTER AHRS_9D_ESKF_SOURCES EXCLUDE REGEX "/(examples|html|interface)/")
add_library(ahrs_9d_eskf STATIC ${AHRS_9D_ESKF_SOURCES})
target_include_directories(ahrs_9d_eskf PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/src/ahrs_9d_eskf")
target_compile_features(ahrs_9d_eskf PUBLIC c_std_99)
target_link_libraries(ahrs_9d_eskf PUBLIC m)
