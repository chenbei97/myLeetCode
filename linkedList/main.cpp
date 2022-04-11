/*
 * @Author: chenbei
 * @Date: 2022-03-11 18:55:30
 * @LastEditTime: 2022-04-04 12:09:34
 * @FilePath: \myLeetCode\linkedList\main.cpp
 * @Description:  
 * @signature: A boy without dreams
 */
/*** 
 * @Author: chenbei
 * @Date: 2022-02-28 08:20:38
 * @LastEditTime: 2022-04-11 15:36:16
 * @Description: linkedList's leetcode analysis
 * @FilePath: \myLeetCode\linkedList\main.cpp
 * @A boy without dreams
 */
#include <iostream>
#include "linkedList.h"
using namespace std;
int main()
{   
    cout<<"merge two ordered linked lists as follows\n";
    _linkedList_mergeTwoOrdered_iteration();
    _linkedList_mergeTwoOrdered_recursion();
    cout<<"get intersection node of two linked lists as follows\n";
    _linkedList_intersectionNode_doublePointers();
    _linkedList_intersectionNode_hashSet();
    cout<<"remove duplicates of sorted linked list as follows\n";
    _linkedList_removeDuplicates_doublePointers(); 
    _linkedList_removeDuplicates_iteration();  
    cout<<"delete duplicates of sorted linked list as follows\n"; 
    _linkedList_deleteDuplicates_iteration();
    cout<<"remove the n node from end of linked list as follows\n"; 
    _linkedList_removeTheNodeFromEnd_stack();
    _linkedList_removeTheNodeFromEnd_iteration();
    _linkedList_removeTheNodeFromEnd_doublePointers();
    cout<<"the list have circular? as follows\n"; 
    _linkedList_circularExist_doublePointers();
    _linkedList_circularExist_hashTable();
    cout<<"the list insertSort as follows\n"; 
    _linkedList_insertSort_iteration();
    cout<<"reverst list as follows\n"; 
    _linkedList_reverseList_iteration();
    _linkedList_reverseList_recursion();
    cout<<"remove list elements as follows\n"; 
    _linkedList_removeElements_recursion();
    _linkedList_removeElements_iteration();
    cout<<"rotate list as follows\n"; 
    _linkedList_rotateList_iteration();
    cout<<"get odd even list as follows\n";
    _linkedList_oddEven_iteration();
    cout<<"add two numbers as follows\n";
    _linkedList_addTwoNumbers_iteration();
    _linkedList_addTwoNumbers_stack();
    cout<<"sort list as follows\n";
    _linkedList_mergeSort_iteration();
    _linkedList_mergeSort_recursion();
    cout<<"get list middle node as follows\n";
    _linkedList_middleNode_iteration();
    _linkedList_middleNode_singlePointer();
    _linkedList_middleNode_doublePointers();
    return 0;
}