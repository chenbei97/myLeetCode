/*** 
 * @Author: chenbei
 * @Date: 2022-04-06 08:00:29
 * @LastEditTime: 2022-04-06 10:18:28
 * @Description: linkedListMergeSort_Iteration.h
 * @FilePath: \myLeetCode\linkedList\linkedListMergeSort_Iteration.h
 * @Signature: A boy without dreams
 */
#ifndef linkedListMergeSortIteration_
#define linkedListMergeSortIteration_
#include "ListNode.h"
#include <iostream>
using namespace std;
class linkedListMergeSortIteration{
    public:
        ListNode* mergeSort(ListNode * root){
            ListNode*h = root;
            int intv = 1;
            int length = 0;
            while (h){
                h = h->next; 
                ++length;//先计算链表长度
            }
            ListNode * ans = new ListNode(0,root);//哑节点
            ListNode * prev = nullptr;
            while (intv<length){ // 大循环
                prev = ans; h = ans->next;
                while (h){ // 小循环,每次h都是全局head节点,一轮intv要找出所有的(h1,h2)
                    ListNode*h1 = h;int i = intv;
                    // 寻找链表的头节点h1
                    while (i && h){ // h从head开始找
                        h = h->next;
                        --i;
                    }
                    // i=0说明,h作为head的链表只有1个元素,只能作为h1用,h2不存在直接break
                    if (i) break; // 这种情况出现在奇数长度,且第1轮intv=1时,最后必然只剩下1个元素

                    // 寻找链表的头节点h2,此时的h的后1个作为h2,i也是
                    ListNode*h2=h;i = intv;
                    while (i && h){
                        h = h->next;// h指针已经被移动到下一个要合并的单元头部
                        --i;
                    }
                    int len1=intv,len2=intv-i; // 一般情况下len1=len2,如果是奇数可能len2=len1-1

                    // 合并h1和h2两个链表
                    while (len1 && len2){
                        if (h1->val<h2->val){ // 更新h1->next,减少len1
                            prev->next = h1; //  pre的next指向当前被归并的节点,它负责衔接res
                            h1 = h1->next;
                            --len1;
                        }
                        else{ // 更新h2->next,减少len2
                            prev->next = h2; // pre的next指向当前被归并的节
                            h2 = h2->next;
                            --len2;
                        }
                        prev = prev->next;//更新prev
                    }
                    prev->next = h1? h1:h2; // h1,h2可能有剩余的节点,直接接在pre后边即可
                    
                    while (len1 > 0 || len2 > 0 ){ // 不能用while(len1||len2),明确要大于0
                        prev = prev->next; // 把pre移动到合并的链表末尾,例如第0和第1个节点末尾就是第1个节点
                        --len1;--len2;
                    }
                    prev->next = h;// 此时的h已经移动到第2个节点,让pre.next衔接上
                }
                intv *= 2; // 下一轮链表归并
            }
            return ans->next;
        }
};
void _linkedList_mergeSort_iteration(){
    linkedListMergeSortIteration solution;
    ListNode *root = new ListNode (3);
    root->next = new ListNode(2);
    root->next->next = new ListNode(0);
    root->next->next->next = new ListNode(-4);
    root->next->next->next->next = new ListNode(4);
    auto ans = solution.mergeSort(root);
    cout<<"mergeSort by iteration as follows\n";
    while (ans){
        cout<<ans->val<<" ";
        ans = ans->next;
    }
    cout<<"\n";
}
#endif//!linkedListMergeSortIteration_