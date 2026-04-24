cmake_minimum_required(VERSION 3.10)

project(NameGen 
    VERSION 1.0.0 
    DESCRIPTION "Multi-style Name Generator"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
    add_compile_options(/W3 /utf-8)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

include_directories(
    ${CMAKE_SOURCE_DIR}/include
)

set(SOURCES
    src/main.cpp
    src/utils/Random.cpp
    src/utils/ConsoleUtils.cpp
    src/generators/NameGenerator.cpp
    src/generators/ChineseNameGenerator.cpp
    src/generators/EnglishNameGenerator.cpp
    src/generators/JapaneseNameGenerator.cpp
)

set(HEADERS
    include/utils/Random.h
    include/utils/ConsoleUtils.h
    include/generators/NameGenerator.h
    include/generators/ChineseNameGenerator.h
    include/generators/EnglishNameGenerator.h
    include/generators/JapaneseNameGenerator.h
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

if(WIN32)
    target_compile_definitions(${PROJECT_NAME} PRIVATE _UNICODE UNICODE)
endif()

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)

if(MSVC)
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
endif()

message(STATUS "========================================")
message(STATUS "Project: ${PROJECT_NAME} v${PROJECT_VERSION}")
message(STATUS "C++ Standard: C++${CMAKE_CXX_STANDARD}")
message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")
message(STATUS "========================================")
