#ifndef linkedListCircularExistDoublePointers_
#define linkedListCircularExistDoublePointers_
#include <iostream>
#include "ListNode.h"
using namespace std;
class linkedListCircularExistDoublePointers{
public:
    bool circularIsExist(ListNode * root){

    }
};
void _linkedList_circularExist_doublePointers(){
    linkedListCircularExistDoublePointers solution;
    ListNode *root = new ListNode (3);
    root->next = new ListNode(2);
    root->next->next = new ListNode(0);
    root->next->next->next = new ListNode(-4);
    root->next->next->next->next = root->next->next;
    cout<<(solution.circularIsExist(root)?"true":"false")<<endl;
}
#endif // !linkedListCircularExistDoublePointers_