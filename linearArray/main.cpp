#include "linearArray.h"
#include <iostream>
using namespace std;
int main()
{
    cout <<"the array's min&max index as follows\n";
    _linearArray_findMinMaxIndex_iteration();
    cout <<"the array's min&max val as follows\n";
    _linearArray_findMinMaxVal_recursion();
    cout <<"the two sums as follows\n";
    _linearArray_twoSum_iteration();
    _linearArray_twoSum_hashTable();
    cout <<"\nthe three sums iteration as follows\n";
    _linearArray_threeSum_iteration();
    cout <<"the three sums doublePointers as follows\n";
    _linearArray_threeSum_doublePointers();
    return 0;
}