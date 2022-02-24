#include "linearArray.h"
#include <iostream>
using namespace std;
int main()
{
    cout <<"the array's min&max index as follows\n";
    _linearArray_findMinMaxIndex_iteration();
    cout <<"the array's min&max val as follows\n";
    _linearArray_findMinMaxVal_recursion();
    return 0;
}