/*** 
 * @Author: chenbei
 * @Date: 2022-03-09 11:20:33
 * @LastEditTime: 2022-03-16 08:19:00
 * @Description: judge linkedList has circular by double pointers
 * @FilePath: \myLeetCode\linkedList\linkedListCircularExist_DoublePointers.h
 * @A boy without dreams
 */
#ifndef linkedListCircularExistDoublePointers_
#define linkedListCircularExistDoublePointers_
#include <iostream>
#include "ListNode.h"
using namespace std;
class linkedListCircularExistDoublePointers{
public:
    bool circularIsExist(ListNode * root){
        if (root == nullptr || root->next == nullptr) {
            return false; // 使用root->next之前事先比较一下
        }
        ListNode* slow = root;
        ListNode* fast = root->next;
        while (slow != fast) {
            if (fast == nullptr || fast->next == nullptr) {
                return false; // 有一个到达nullptr就返回false没有环
            }
            slow = slow->next; // 走1步
            fast = fast->next->next; // 走2步
        }
        return true;
    }
};
void _linkedList_circularExist_doublePointers(){
    linkedListCircularExistDoublePointers solution;
    ListNode *root = new ListNode (3);
    root->next = new ListNode(2);
    root->next->next = new ListNode(0);
    root->next->next->next = new ListNode(-4);
    root->next->next->next->next = root->next->next;
    cout<<(solution.circularIsExist(root)?"true":"false")<<endl;
}
#endif // !linkedListCircularExistDoublePointers_