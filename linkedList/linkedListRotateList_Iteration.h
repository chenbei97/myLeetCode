/*** 
 * @Author: chenbei
 * @Date: 2022-04-02 11:30:01
 * @LastEditTime: 2022-04-02 15:53:02
 * @Description: linkedListRotateList_Iteration.h
 * @FilePath: \myLeetCode\linkedList\linkedListRotateList_Iteration.h
 * @A boy without dreams
 */
#ifndef linkedListRotateListIteration_
#define linkedListRotateListIteration_
#include "ListNode.h"
#include <iostream>
using namespace std;
class linkedListRotateListIteration{
    public:
        ListNode* rotate(ListNode * root,int k=0){
            // 移动0次或者root为空或者root只有1个节点都返回本身即可
            if (!root || !root->next || k == 0 ) return root;
            // 先获取链表长度
            int length = 0;
            ListNode * iter = root;
            while (iter->next){ // 希望遍历结束后iter指向的是last方便后边操作
                iter = iter->next;
                ++length; 
            }
            ++length;//真正的链表长度
        
            // 如果123456,k=2不是想要输出345612,而是561234,这其实就是首节点向前移动
            // 新的首节点对应原来链表在位置length-k的那个节点,但是要考虑k是整数倍length的情况,必须对length取余
            int firstIdx = k%length==0?0:length-k%length; // 新首节点对应原链表的位置
            if (firstIdx == 0) return root; //又回到原来位置
            // 如果首节点位置不是0它的前1个就是尾节点,否则尾节点就是length-1
            int lastIdx = firstIdx-1;// 新尾节点对应原链表的位置,不需要再判断firstIdx是否为0,这情况已经return
            
            // 现在iter位置在length-1,从位置5到0,1,2,3共4个单位
            iter->next = root;//成循环链表
            ++lastIdx;// 它向前移动lastIdx+1个单位即可到达新的链表尾节点
            while (lastIdx--) iter = iter->next; // 现在iter的位置就是新尾节点
            ListNode * ans = iter->next; // 下一个就是首节点
            iter->next = nullptr; // 新的尾节点和新的首节点之间断开
            return ans;
        }
};
void _linkedList_rotateList_iteration(){
    linkedListRotateListIteration solution;
    ListNode *root = new ListNode (0);
    root->next = new ListNode(1);
    root->next->next = new ListNode(2);
    // root->next->next->next = new ListNode(4);
    // root->next->next->next->next = new ListNode(5);
    // root->next->next->next->next->next = new ListNode(6);
    auto ans = solution.rotate(root,4);
    cout<<"rotate list by iteration as follows\n";
    while (ans){
        cout<<ans->val<<" ";
        ans = ans->next;
    }
    cout<<"\n";
}
#endif//!linkedListRotateListIteration_