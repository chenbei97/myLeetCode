#ifndef linkedListIntersectionNodeDoublePointers_
#define linkedListIntersectionNodeDoublePointers_
#include "ListNode.h"
#include <iostream>
using namespace std;
class linkedListIntersectionNodeDoublePointers{
    public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;
        ListNode * pa = headA, *pb =headB;
        while (pa != pb){ // next和val均相等
            // 可以这样写,==优先级高于三元运算符?
            // pa = pa == nullptr ? headB : pa->next; // pa为空就让它等于headB,否则等于pa的next
            // pb = pb == nullptr ? headA : pb->next; // 同理
            if (pa) pa = pa->next;
            else pa = headB;
            if (pb) pb = pb->next;
            else pb = headA;
        } // 退出while时不是相交节点就都是空节点
        return pa; // pb也可
    }
};
void _linkedList_intersectionNode_doublePointers(){
    linkedListIntersectionNodeDoublePointers solution;
    ListNode n1(4);ListNode n2(1);
    ListNode m1(5);ListNode m2(6);ListNode m3(1);
    ListNode s1(8);ListNode s2(4);ListNode s3(5);

    s1.next = & s2; s2.next = & s3;
    n1.next = &n2; n2.next = &s1;
    m1.next = &m2; m2.next = &m3; m3.next = &s1;
    auto ans = solution.getIntersectionNode(&n1,&m1);
    if (ans) cout <<"double pointers:intersection node val is "<<ans->val<<endl;
    else cout <<"double pointers:intersection node not exists\n";
}
#endif // !linkedListIntersectionNodeDoublePointers_