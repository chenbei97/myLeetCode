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
    cout <<"merge two sorted arrays as follows\n";
    _linearArray_mergeSortedArray_iteration();
    _linearArray_mergeSortedArray_doublePointers();
    cout<<"search rotated sorted array element's idx as follows\n";
    _linearArray_searchRotateSorted_binary();
    cout<<"the two of power as follows\n";
    _linearArray_twoOfPower();
    cout<<"find the single number as follows\n";
    _linearArray_findSingleNumber_bit();
    _linearArray_findSingleNumber_hashTable();
    cout<<"find all non repeating subset as follows\n";
    _linearArray_nonRepeatingSubset_iteration();
    _linearArray_nonRepeatingSubset_recursion();
    cout<<"the array sorted squares as follows\n";
    _linearArray_sortedSquare_iteration();
    _linearArray_sortedSquare_doublePointers();
    cout<<"the relative order array as follows\n";
    _linearArray_relativeOrder_hashTable();
    return 0;
}