/*
 * @Author: chenbei
 * @Date: 2022-02-14 07:58:04
 * @LastEditTime: 2022-03-15 08:45:59
 * @LastEditors: chenbei
 * @Description: linearArray's leetcode main.cpp
 * @FilePath: \myLeetCode\linearArray\main.cpp
 */
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
    _linearArray_relativeOrder_iteration();
    cout <<"the majority element as follows\n";
    _linearArray_majorityElement_hashTable();
    _linearArray_majorityElement_sort();
    cout <<"the max subArray sum as follows\n";
    _linearArray_maxSubArray_dynamicProgramming();
    _linearArray_maxSubArray_iteration();
    cout<<"the nearby duplicates as follows\n";
    _linearArray_nearbyDuplicates_hashTable();
    _linearArray_nearbyDuplicates_hashSet();
    cout<<"the sudoku is valid? as follows\n";
    _linearArray_validSudoku_iteration();
    cout<<"the best time to sell stocks as follows\n";
    _linearArray_bestTimeToSellStocks_iteration();
    _linearArray_bestTimeToSellStocks_dynamicProgramming();
    _linearArray_bestTimeToSellStocks_greedy();
    cout<<"how to move zeros to end as follows\n";
    _linearArray_moveZerosToEnd_doublePointers();
    cout<<"how to spiral order matrix as follows\n";
    _linearArray_spiralMatrix_iteraton();
    return 0;
}