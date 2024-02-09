file(GLOB_RECURSE TEST_SOURCES "src/*.c")

list(APPEND TEST_SOURCES
	"vendor/munit/munit.h"
	"vendor/munit/munit.c"
)

add_executable(myproject-tests ${TEST_SOURCES})

target_include_directories(myproject-tests PRIVATE
	${myproject_IncludeDirectories}
	"vendor/munit"
)

target_link_libraries(myproject-tests PRIVATE myproject)
