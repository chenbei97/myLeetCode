/*** 
 * @Author: chenbei
 * @Date: 2022-04-02 10:42:30
 * @LastEditTime: 2022-04-02 10:57:24
 * @Description: linkedListRemoveElements_Recursion.h
 * @FilePath: \myLeetCode\linkedList\linkedListRemoveElements_Recursion.h
 * @A boy without dreams
 */
#include "ListNode.h"
#ifndef linkedListRemoveElementsRecursion_
#define linkedListRemoveElementsRecursion_
#include <iostream>
using namespace std;
class linkedListRemoveElementsRecursion{
    public:
        ListNode* removeElements(ListNode * root,int val){
            if (!root) return root;
            // 递归到最深处,到达last节点,last.next=nullptr直接返回
            // 之后下边操作相当于last.next = nullptr
            root->next = removeElements(root->next,val);
            // 然后比较root.val和val是否相等,相等就放弃last节点,返回last.next=None
            // 这是为了下一轮递归的root.next接收的还是None,此时的root是上一轮递归root的prev
            // 如果不相等,说明root可以保留,下一轮递归的root.next=root(上一轮保留的非空root)
            // 如此进行下去,最后返回的root是去除了等于val节点的链表
            return  root->val==val? root->next : root;
        }
};
void _linkedList_removeElements_recursion(){
    linkedListRemoveElementsRecursion solution;
    ListNode *root = new ListNode (3);
    root->next = new ListNode(2);
    root->next->next = new ListNode(0);
    root->next->next->next = new ListNode(3);
    root->next->next->next->next = new ListNode(4);
    auto ans = solution.removeElements(root,3);
    cout<<"removeElements by recursion as follows\n";
    while (ans){
        cout<<ans->val<<" ";
        ans = ans->next;
    }
    cout<<"\n";
}
#endif//!linkedListRemoveElementsRecursion_