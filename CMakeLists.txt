cmake_minimum_required(VERSION 3.30.0)
project(test VERSION 0.0.1)

add_executable(test main.cpp)

add_subdirectory(../FFReadWriter FFReadWriter)

target_compile_features(test PRIVATE cxx_std_11)

target_include_directories(test PRIVATE ../FFReadWriter/Sources/include)

target_link_libraries(test PRIVATE FFReadWriter)

target_link_directories(test PRIVATE
    ${CMAKE_SOURCE_DIR}/build/FFReadWriter
    ${CMAKE_SOURCE_DIR}/../FFReadWriter/Sources/FFReadWriter/ffmpeg-sdk-osx/lib
)