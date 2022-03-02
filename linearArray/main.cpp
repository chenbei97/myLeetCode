#include "linearArray.h"
#include <iostream>
using namespace std;
int main()
{
    cout <<"the array's min&max index as follows\n";
    _linearArray_findMinMaxIndex_iteration();
    cout <<"the array's min&max val as follows\n";
    _linearArray_findMinMaxVal_recursion();
    _linearArray_findMinMaxVal_stack();
    cout <<"the two sums as follows\n";
    _linearArray_twoSum_iteration();
    _linearArray_twoSum_hashTable();
    cout <<"\nthe three sums iteration as follows\n";
    _linearArray_threeSum_iteration();
    cout <<"the three sums doublePointers as follows\n";
    _linearArray_threeSum_doublePointers();
    cout <<"the cloest three sums iteration as follows\n";
    _linearArray_threeSumClosest_iteration();
    cout <<"the cloest three sums doublePointers as follows\n";
    _linearArray_threeSumClosest_doublePointers();
    cout <<"remove sorted array duplicates as follows\n";
    _linearArray_removeDuplicates_doublePointers();
     cout <<"remove array specified element as follows\n";
    _linearArray_removeElement_doublePointers();
    return 0;
}