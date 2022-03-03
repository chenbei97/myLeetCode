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
    return 0;
}