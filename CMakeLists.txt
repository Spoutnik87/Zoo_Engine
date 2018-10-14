cmake_minimum_required(VERSION 3.0)

if(UNIX)
    SET(CMAKE_CXX_FLAGS -pthread)
endif()

project(ZooEngine)

file(GLOB_RECURSE SRC "src/*.cpp")

include_directories(include)
include_directories($(CMAKE_CURRENT_SOURCE_DIR)/dependencies/SFML/include)
include_directories($(CMAKE_CURRENT_SOURCE_DIR)/dependencies/boost)

link_directories($(CMAKE_CURRENT_SOURCE_DIR)/dependencies/SFML/lib)
link_directories($(CMAKE_CURRENT_SOURCE_DIR)/dependencies/boost/stage/lib)

add_executable(ZooEngine ${SRC})

if(CMAKE_BUILD_TYPE STREQUAL DEBUG)
    message("debug mode")
    target_link_libraries(ZooEngine sfml-audio-d sfml-graphics-d sfml-window-d sfml-system-d boost_system boost_filesystem)
else()
    message("release mode")
    target_link_libraries(ZooEngine sfml-audio sfml-graphics sfml-window sfml-system boost_system boost_filesystem)
endif()