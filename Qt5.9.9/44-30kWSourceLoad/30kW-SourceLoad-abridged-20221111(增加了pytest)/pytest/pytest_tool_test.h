#ifndef PYTEST_TOOL_TEST_H
#define PYTEST_TOOL_TEST_H
#include <pytest/pytest_tool_api.h>

enum class TOOL_TEST {ImportTest,ArgTest,ConversionTest};

void test_tool(TOOL_TEST test)
{
    switch (test) {
            case TOOL_TEST::ImportTest :test_import_module();break;
            case TOOL_TEST::ArgTest :test_analytic_arg();break;
            case TOOL_TEST::ConversionTest :test_str_conversion();break;
    }
}
#endif // PYTEST_TOOL_TEST_H
