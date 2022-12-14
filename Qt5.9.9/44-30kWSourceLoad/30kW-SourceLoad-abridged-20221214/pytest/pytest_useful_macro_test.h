#ifndef PYTEST_USEFUL_MACRO_TEST_H
#define PYTEST_USEFUL_MACRO_TEST_H
#include <pytest/pytest_useful_macro_api.h>

enum class USEFULLMACRO_TEST{UsefullMacroTest,RefCountTest};

void test_useful_macro(USEFULLMACRO_TEST test)
{
        UNREACHABLE_Test unr = UNREACHABLE_Test::UNR0;
        switch (test) {
                case USEFULLMACRO_TEST::UsefullMacroTest: test_useful_macro(unr);break;
                case USEFULLMACRO_TEST::RefCountTest: test_ref_count();break;
        }
}
#endif // PYTEST_USEFUL_MACRO_TEST_H
