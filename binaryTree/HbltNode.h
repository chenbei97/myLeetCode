#ifndef HbltNode_
#define HbltNode_
#include <utility>
using namespace std;
struct HbltNode
{
    pair<int,int> node; // 第1个是编号值,第2个是元素值(int)
    HbltNode * left , * right;
    
    // 5种左高树节点的初始化方法
    HbltNode(): node(make_pair(1,0)),left(nullptr),right(nullptr){};
    HbltNode(pair<int,int> theNode) : node(theNode),left(nullptr),right(nullptr){};
    HbltNode(pair<int,int> theNode,HbltNode*theLeft,HbltNode*theRight) :
        node(theNode),left(theLeft),right(theRight){};
    HbltNode(int number ,int val){
        node.first = number;
        node.second = val;
        left = nullptr ;
        right = nullptr;
    };
    HbltNode(int number,int val,HbltNode*theLeft,HbltNode*theRight){
        node.first = number;
        node.second = val;
        left = theLeft ;
        right = theRight;
    }
};

#endif // !HbltNode_