cmake_minimum_required(VERSION 3.25)

project(myproject
    VERSION 0.1.0
    DESCRIPTION ""
    HOMEPAGE_URL "" 
    LANGUAGES C ASM
)

option(MY_ENABLE_TESTING "Should cmake build test executables?" ON)
option(MY_BUILD_EXAMPLES "Should cmake build examples?" ON)
option(MY_BUILD_SHARED_LIBRARIES "Should cmake build library as shared or static?" ON)
option(MY_INSTALL "Install the application after build" OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build/lib")

file(GLOB_RECURSE SOURCES "include/*.h" "include/*.inc" "src/*.c" "src/*.s")

if(MY_BUILD_SHARED_LIBRARIES)
    add_library(myproject SHARED ${SOURCES})

	target_compile_definitions(myproject PUBLIC MY_EXPORT)
else()
    add_library(myproject STATIC ${SOURCES})
endif()

target_precompile_headers(myproject
    PUBLIC "include/myproject/pch.h"
)

target_include_directories(myproject
    PUBLIC ${CMAKE_SOURCE_DIR}/include
)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED TRUE)

if(MY_ENABLE_TESTING)
	add_subdirectory(tests)
endif()

if(MY_BUILD_EXAMPLES)
	add_subdirectory(examples)
endif()

if(MY_INSTALL)
	# TODO create install targets
endif()
