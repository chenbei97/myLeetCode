#ifndef characterStringCalculateExpressionStack_
#define characterStringCalculateExpressionStack_
#include <string>
#include <vector>
#include <iostream>
#include <numeric>
using namespace std;
class characterStringCalculateExpressionStack{
    public:
        int calculate(string s){
            vector<int> stk;//为了方便使用vector作为栈,这样获取元素不必删除才能获取
            int num = 0; // 用于计算存放到栈的数字
            char sign = '+'; // 首个数字之前认为是+号,sign总是滞后变化
            for(int i = 0;i<s.length();i++){ // 遍历每个字符
                if (isdigit(s[i])){ // 是数字的话这样计算
                    // 如果是个位数,因为是数字只可能是0-9,那么int('9'-'0')=9
                    // 十位数,例如17,先计算1,得到num=1,然后是7,1×10+int('7'-'0')=17
                    // 百位数同理
                    num = num*10 + int(s[i]-'0'); // num更新结束后,就作为待处理的数字
                    // 如何处理num取决于num后边的运算符
                }
                // 注意要用并列关系,不是数字且不是空格
                // 为何要加条件"i==s.length()-1"呢?假如最后1个字符是数字B,它前边是*
                // *之前的数字A之前是-,因为A是数字,num=A,然后下个字符*,不是数字也不是空格
                // 由于sign是上一次更新的-,执行case'-'选项,那么会把-A(-num)存到stk,num=0,然后sign更新到*
                // 下个字符是B,B是数字,计算num=B,如果不加后边的条件,5算完没有进行下一步操作就会丢失
                // 加了以后,因为sign=*,那么执行栈顶元素-A*B再入栈就不会丢失信息
                if ((!isdigit(s[i]) && s[i] != ' ') || i==s.length()-1)
                { 
                    switch (sign)
                    {
                        case '+':
                            stk.push_back(num);//num后面是+就直接入栈
                            break;
                        case '-':
                            stk.push_back(-num);//减法就入个相反数
                            break;
                        case '*':
                            // 因为是有效表达式,遇见*之前必定有数字已经入栈
                            // 不必担心back()是空的
                            stk.back()*= num; // 计算数字与栈顶元素并更新栈顶元素
                            break;
                        case '/':
                            stk.back()/= num; // 计算数字与栈顶元素并更新栈顶元素
                            break;
                    }
                    num = 0; //运算符后面的数字重新开始计算
                    sign = s[i];//把sign更新为现在的字符,变化的值用于下1次计算
                }
            }
            return accumulate(stk.begin(), stk.end(), 0); // 初始值为0
        }
};
void _characterString_calculateExpression_stack(){
    characterStringCalculateExpressionStack solution;
    string s("3 * 17 + 100 / 3 - 5 * 3");//3 * 17 + 100 / 3 - 5 * 3 
    int ans = solution.calculate(s);
    cout<<"the string expression is calculated,ans is "<<ans<<endl;
}
#endif // !characterStringCalculateExpressionStack_