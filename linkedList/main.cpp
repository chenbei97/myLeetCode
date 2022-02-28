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
    return 0;
}