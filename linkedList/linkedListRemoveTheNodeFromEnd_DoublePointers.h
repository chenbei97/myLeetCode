/*** 
 * @Author: chenbei
 * @Date: 2022-03-02 13:13:57
 * @LastEditTime: 2022-03-16 08:23:36
 * @Description: remove the node from end by double pointers
 * @FilePath: \myLeetCode\linkedList\linkedListRemoveTheNodeFromEnd_DoublePointers.h
 * @A boy without dreams
 */
#ifndef linkedListRemoveTheNodeFromEndDoublePointers_
#define linkedListRemoveTheNodeFromEndDoublePointers_
#include "ListNode.h"
#include <iostream>
#include <algorithm>
using namespace std;
class linkedListRemoveTheNodeFromEndDoublePointers{
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n){
            // 假设链表长度m,n是倒数第n个节点,故第m-n个节点是这个节点的前1个
            // n = m 时其实就是第1个节点的前1个
            ListNode * slow = head,*fast = head;
            while (n > 0){ // 执行n次while
                fast = fast->next;//fast实际上从head移动了n次,在第n+1个节点
                n--;
            }
            if (!fast) return slow->next; // 执行n次while链表到头说明n=m,也就是删除链表的第1个节点

            while (fast->next){ // 如果n<m,那么slow和fast中间相隔n个节点
                fast = fast->next; // fast->next为空说明fast为第m个节点,而此时fast是第n+1个节点
                slow = slow->next; // 所以fast需要移动m-n-1次,slow也一起移动了m-n-1次
            }
            // 现在slow在位置1,移动m-n-1次就到了第m-n个节点
            // 这个节点就是要移除的节点前一个节点
            slow->next = slow->next->next; // 让这个节点的next不指向被移除的节点即可
            return head;
        }
};
void _linkedList_removeTheNodeFromEnd_doublePointers(){
    linkedListRemoveTheNodeFromEndDoublePointers solution;
    ListNode * root = new ListNode (1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);
    root->next->next->next = new ListNode(4);
    root->next->next->next->next = new ListNode(5);
    auto ans = solution.removeNthFromEnd(root,2);
    cout<<"double pointers: remove the n node of linkedList\n";
    while (ans){
        cout<<ans->val<<" ";
        ans = ans->next;
    }
    cout<<"\n";
}
#endif // !linkedListRemoveTheNodeFromEndDoublePointers_