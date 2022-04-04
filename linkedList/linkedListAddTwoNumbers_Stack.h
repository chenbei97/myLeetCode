/*
 * @Author: chenbei
 * @Date: 2022-04-04 12:08:08
 * @LastEditTime: 2022-04-04 12:44:27
 * @FilePath: \myLeetCode\linkedList\linkedListAddTwoNumbers_Stack.h
 * @Description: linkedListAddTwoNumbers_Stack.h
 * @Signature: A boy without dreams
 */
#ifndef linkedListAddTwoNumbersStack_
#define linkedListAddTwoNumbersStack_
#include "ListNode.h"
#include <iostream>
#include <vector>
using namespace std;
class linkedListAddTwoNumbersStack{
    public:
        ListNode* addTwoNumbers(ListNode * root1,ListNode * root2){
            ListNode* dummy =new ListNode(0);
            int carry=0; // 进位
            vector<int> v1,v2;//two stacks
            while(root1){
                v1.push_back(root1->val);//入栈
                root1=root1->next;
            }
            while (root2){
                v2.push_back(root2->val);
                root2=root2->next;
            }     
            while (!v1.empty() || !v2.empty()){
                //cout<<"v1.back()="<<v1.back()<<endl;
                int val1=0,val2=0;
                if (!v1.empty()){
                    val1 = v1.back();
                    v1.pop_back();
                }
                if (!v2.empty()){
                    val2 = v2.back();
                    v2.pop_back();
                }
                int sum = val1+val2+carry;
                carry = sum/10;
                sum = sum%10;
                ListNode* node = new ListNode(sum,dummy->next);
                dummy->next = node;
            }
            if (carry){
                ListNode* node = new ListNode(carry,dummy->next);
                dummy->next = node;
            }
            return dummy->next;
        }
};
void _linkedList_addTwoNumbers_stack(){
    linkedListAddTwoNumbersStack solution;
    ListNode *root1 = new ListNode (7),*root2 = new ListNode (5);
    root1->next = new ListNode(2);root2->next = new ListNode(6);
    root1->next->next = new ListNode(4);root2->next->next = new ListNode(4);
    root1->next->next->next = new ListNode(3);
    auto ans = solution.addTwoNumbers(root1,root2);
    cout<<"add list numbers by stack as follows\n";
    while (ans){ 
        cout<<ans->val<<" ";
        ans = ans->next;
    }
    cout<<"\n";
}
#endif//!linkedListAddTwoNumbersStack_