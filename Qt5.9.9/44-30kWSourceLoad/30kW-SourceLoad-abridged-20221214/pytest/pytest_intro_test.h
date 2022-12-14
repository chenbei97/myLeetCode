#ifndef PYTEST_INTRO_TEST_H
#define PYTEST_INTRO_TEST_H
#include <pytest/pytest_intro_api.h>

enum class INTRO_TEST {PythonTest,PackageTest};

void test_intro(INTRO_TEST which)
{
    switch (which) {
        case INTRO_TEST::PythonTest: test_python();break;
        default:test_plot();break;
    }
}
#endif // PYTEST_INTRO_TEST_H
