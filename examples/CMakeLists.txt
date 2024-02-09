file(GLOB_RECURSE EXAMPLE_SOURCES "src/*.h" "src/*.c")

add_executable(myproject-example ${EXAMPLE_SOURCES})

target_include_directories(myproject-example PRIVATE ${myproject_IncludeDirectories})

target_link_libraries(myproject-example PRIVATE myproject)
