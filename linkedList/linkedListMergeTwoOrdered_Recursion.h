#ifndef linkedListMergeTwoOrderedRecursion_
#define linkedListMergeTwoOrderedRecursion_
#include "ListNode.h"
#include <iostream>
using namespace std;
class linkedListMergeTwoOrderedRecursion{
    public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            if (!list1) return list2;
            if (!list2) return list1;
            if (list1->val < list2->val){
                list1->next = mergeTwoLists(list1->next,list2);
                return list1;
            }
            else{
                list2->next = mergeTwoLists(list1,list2->next);
                return list2;
            }
        }
};
void _linkedList_mergeTwoOrdered_recursion(){
    linkedListMergeTwoOrderedRecursion solution;
    ListNode * t1;
    ListNode * t2;
    t1 = new ListNode(1);
    t1->next = new ListNode(2);
    t1->next->next = new ListNode(4);
    //cout<<t1->val<<" "<<t1->next->val<<" "<<t1->next->next->val<<endl;
    t2 = new ListNode(1);
    t2->next = new ListNode(3);
    t2->next->next = new ListNode(4);
    // t2->next->next->next = new ListNode(6);
    ListNode* ans = solution.mergeTwoLists(t1,t2);
    cout<<"other recursion method\n";
    while (ans!= nullptr)
    {
        cout<<ans->val<<" ";
        ans = ans->next;
    }
    cout<<"\n";

}
#endif // !linkedListMergeTwoOrderedRecursion_