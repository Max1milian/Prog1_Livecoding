cmake_minimum_required(VERSION 3.20.0)
project(LiveCoding
	LANGUAGES C
	VERSION 0.0.1
	DESCRIPTION "LiveCoding Übung"
	HOMEPAGE_URL "")

if(MSVC)
    add_compile_options(/W3 /WX /permissive)
else()
    add_compile_options(-Wextra -Wall -Werror -pedantic-errors -fanalyzer)
endif(MSVC)


file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)
add_executable(${PROJECT_NAME} ${SRC_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_options(${PROJECT_NAME} PRIVATE -std=c11) 
