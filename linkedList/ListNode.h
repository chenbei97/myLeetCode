/*** 
 * @Author: chenbei
 * @Date: 2022-02-28 08:14:33
 * @LastEditTime: 2022-03-16 08:24:31
 * @Description: ListNode.h
 * @FilePath: \myLeetCode\linkedList\ListNode.h
 * @A boy without dreams
 */
#ifndef ListNode_
#define  ListNode_
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#endif // !ListNode_