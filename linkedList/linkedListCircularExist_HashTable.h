#ifndef linkedListCircularExistHashTable_
#define linkedListCircularExistHashTable_
#include <iostream>
#include <unordered_map>
#include "ListNode.h"
using namespace std;
class linkedListCircularExistHashTable{
public:
    bool circularIsExist(ListNode * root){
        unordered_set<ListNode*> seen;
        while (root != nullptr) { // 遍历所有节点
            if (seen.count(root)) {// 该节点已经存在于哈希表中
                return true; // 说明该链表是环形链表
            }
            seen.insert(root); // 否则就把这个节点加入
            root = root->next;
        }
        return false;
    }
};
void _linkedList_circularExist_hashTable(){
    linkedListCircularExistHashTable solution;
    ListNode *root = new ListNode (3);
    root->next = new ListNode(2);
    root->next->next = new ListNode(0);
    root->next->next->next = new ListNode(-4);
    root->next->next->next->next = root->next->next;
    cout<<(solution.circularIsExist(root)?"true":"false")<<endl;
}
#endif // !linkedListCircularExistHashTable_