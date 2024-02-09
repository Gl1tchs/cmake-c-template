#include <munit.h>
#include <stdlib.h>

static MunitResult test_foo(const MunitParameter params[], void* user_data) {
	i8 number = 5;
	munit_assert_int32(number, ==, 5);

	return MUNIT_OK;
}

int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
	MunitTest test_suite_tests[] = {
		{ (char*)"/tests/foo", test_foo, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
		// this needs to be here to say the array is over
		{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
	};

	const MunitSuite test_suite = {
		(char*)"myproject",
		test_suite_tests,
		NULL,
		1,
		MUNIT_SUITE_OPTION_NONE
	};

	return munit_suite_main(&test_suite, (void*)"myproject", argc, argv);
}
