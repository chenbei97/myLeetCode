#ifndef linkedListIntersectionNodeHashSet_
#define linkedListIntersectionNodeHashSet_
#include "ListNode.h"
#include <unordered_set>
#include <unordered_map>
#include <iostream>
using namespace std;
class linkedListIntersectionNodeHashSet{
    public:
        ListNode *getIntersectionNodeSet(ListNode *headA, ListNode *headB){
            unordered_set<ListNode*> s; // 存的是地址
            ListNode * t = headA;
            while (t){ // 把链表A所有节点插入到哈希集合
                cout<<"t = "<<t << " t->val = "<<t->val<<endl;
                s.insert(t);
                t = t->next;
            }
            t = headB;
            while (t){ // 遍历链表B的每个节点,如果set存在这个就返回
                cout<<"t = "<<t << " t->val = "<<t->val<<" s.count(t) = "<<s.count(t)<<endl;
                if (s.count(t))
                    return t;
                t = t->next;
            }
            return nullptr;
        }
        ListNode *getIntersectionNodeMap(ListNode *headA, ListNode *headB){
            unordered_map<ListNode*,int> s; // 存的是地址
            ListNode * t = headA;
            while (t){ // 把链表A所有节点插入到哈希集合
                cout<<"t = "<<t << " t->val = "<<t->val<<endl;
                s[t] = t->val;
                t = t->next;
            }
            t = headB;
            while (t){ // 遍历链表B的每个节点,如果set存在这个就返回
                cout<<"t = "<<t << " t->val = "<<t->val<<" s.count(t) = "<<s.count(t)<<endl;
                if (s.count(t))
                    return t;
                t = t->next;
            }
            return nullptr;
        }
};
void _linkedList_intersectionNode_hashSet(){
    linkedListIntersectionNodeHashSet solution;
    ListNode n1(4);ListNode n2(1);
    ListNode m1(1);ListNode m2(6);ListNode m3(1);
    ListNode s1(8);ListNode s2(4);ListNode s3(5);

    s1.next = & s2; s2.next = & s3;
    n1.next = &n2; n2.next = &s1;
    m1.next = &m2; m2.next = &m3; m3.next = &s1;
    auto ans = solution.getIntersectionNodeSet(&n1,&m1);
    if (ans) cout <<"hashSet:intersection node val is "<<ans->val<<endl;
    else cout <<"hashSet:intersection node not exists\n";
    ans = solution.getIntersectionNodeMap(&n1,&m1);
    if (ans) cout <<"hashMap:intersection node val is "<<ans->val<<endl;
    else cout <<"hashMap:intersection node not exists\n";
}
#endif // !linkedListIntersectionNodeHashSet_