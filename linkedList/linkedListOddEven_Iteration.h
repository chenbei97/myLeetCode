/*** 
 * @Author: chenbei
 * @Date: 2022-04-02 11:30:48
 * @LastEditTime: 2022-04-02 16:17:14
 * @Description: linkedListOddEven_Iteration.h
 * @FilePath: \myLeetCode\linkedList\linkedListOddEven_Iteration.h
 * @A boy without dreams
 */
#ifndef linkedListOddEvenIteration_
#define linkedListOddEvenIteration_
#include "ListNode.h"
#include <iostream>
using namespace std;
class linkedListOddEvenIteration{
    public:
        ListNode* oddEven(ListNode * head){
        if (head == nullptr)return head;
        ListNode* evenHead = head->next; //偶数链表起点
        ListNode* odd = head;//奇数链表起点
        ListNode* even = evenHead;//维护2个指针odd和even
        while (even != nullptr && even->next != nullptr) { 
            //因为even在后,它和even.next都不为空时odd才能移动到even.next
            odd->next = even->next;//奇数节点的下一个在偶数节点的下一个
            odd = odd->next;// 更新odd到下一个
            even->next = odd->next;//偶数节点的下一个是已更新的odd的下一个
            even = even->next;// 更新even
        }
        // 此时odd是最后1个奇数节点
        odd->next = evenHead;//把偶数链表接在后边
        return head;
    }
};
void _linkedList_oddEven_iteration(){
    linkedListOddEvenIteration solution;
    ListNode *root = new ListNode (1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);
    root->next->next->next = new ListNode(4);
    root->next->next->next->next = new ListNode(5);
    auto ans = solution.oddEven(root);
    cout<<"get oddEven by iteration as follows\n";
    while (ans){
        cout<<ans->val<<" ";
        ans = ans->next;
    }
    cout<<"\n";
}
#endif//!linkedListOddEvenIteration_