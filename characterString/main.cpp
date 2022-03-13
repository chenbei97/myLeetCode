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
    cout<<"calculate expression as follows\n";
    _characterString_calculateExpression_stack();
    cout<<"string is palindrome? as follows\n";
    _characterString_palindrome_greedy();
    _characterString_palindrome_enum();
    cout<<"excel title to number as follows\n";
    _characterString_excelTitleToNumber();
    cout<<"excel number to title as follows\n";
    _characterString_excelNumberToTitle();
    cout<<"the decode string as follows\n";
    _characterString_decodeString_iteration();
    _characterString_decodeString_stack();
    _characterString_decodeString_recursion();
    cout<<"jewels and stones as follows\n";
    _charaterString_jewelsStones_hashSet();
    _charaterString_jewelsStones_iteration();
    return 0;
}