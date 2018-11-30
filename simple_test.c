#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

/* functions to test */
extern int number_plus_one(int number);

/* A test case that does nothing and succeeds. */
static void null_test_success(void **state) {
    (void) state; /* unused */
}

static void test_number_plus(void **state) {
    assert_int_equal(number_plus_one(2), 5);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(null_test_success),
        cmocka_unit_test(test_number_plus),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
