#ifndef linkedListInsertSortIteration_
#define linkedListInsertSortIteration_
#include "ListNode.h"
#include <iostream>
using namespace std;
class linkedListInsertSortIteration{
    public:
        ListNode* insertSort(ListNode*root){
            if (!root) return root;
            ListNode*dummy = new ListNode(0,root); //哑节点方便在第1个节点前插入节点
            ListNode*lastSorted = root;//指向最后1个排好序的节点,初始指向root
            ListNode*cur = root->next;//总是lastSorted节点的下一个,初始指向第2个元素
            while (cur){
                if (lastSorted->val<=cur->val){
                    lastSorted = lastSorted->next;//最简单的情况,cur更大直接尾插
                    // 最后1个排序的节点后移,当前的cur就等于lastSorted.next
                    // 不使用lastSorted=cur是因为cur后边会变化,会导致lastSorted也变,而next是不会变的
                }
                else{
                    ListNode*prev = dummy;
                    while (prev->next->val<=cur->val){//从头节点开始依次与cur比较大小
                        prev = prev->next;//使用prev.next而不直接prev指向root的原因是
                        // 希望while停止和prev是在要插入的位置前1个
                        // 如果是prev<cur,prev最终到达的是插入的位置而不是前1个,cur就无法和上一个进行衔接
                    }
                    lastSorted->next = cur->next;//cur移到前边了,cur的next由lastSorted接手
                    cur->next = prev->next; // 与后1个节点衔接,这个由之前的prev.next指向
                    prev->next = cur;// 和前1个节点衔接
                }
                cur = lastSorted->next; // 判断下一个未排序的第1个元素
            }
            return dummy->next;
        }
};
void _linkedList_insertSort_iteration(){
    linkedListInsertSortIteration solution;
    ListNode * root = new ListNode(10);
    root->next = new ListNode(8);
    root->next->next = new ListNode(9);
    root->next->next->next = new ListNode(6);
    root->next->next->next->next = new ListNode(7);
    root->next->next->next->next->next = new ListNode(3);
    root->next->next->next->next->next->next = new ListNode(5);
    root->next->next->next->next->next->next->next = new ListNode(2);
    root->next->next->next->next->next->next->next->next = new ListNode(2);
    auto ans = solution.insertSort(root);
    while (ans){
        cout<<ans->val<<" ";
        ans= ans->next;
    }
    cout<<"\n";
}
#endif // !linkedListInsertSortIteration