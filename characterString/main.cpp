#include "characterString.h"
#include <iostream>
using namespace std;
int main()
{
    cout<<"string backspace problem as follows\n";
    _characterString_backspaceCompare_stack();
    _characterString_backspaceCompare_string();
    _characterString_backspaceCompare_doublePointers();
    cout<<"the parentheses's validity as follows\n";
    _characterStringValidParenthesesStack();
    return 0;
}