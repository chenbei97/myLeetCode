#ifndef linearArrayTwoOfPower_
#define linearArrayTwoOfPower_
#include <iostream>
#include <string>
using namespace std;
class linearArrayTwoOfPower{
    public:
        bool isPowerOfTwo_iteration(int num){
            if (num <0) return false;
            if (num == 1){idx = 0;return true;}
            int x = 1;
            while (true){
                int ans=1 ;
                for(int i = 0; i<x;i++)
                    ans = ans*2;
                if (ans == num) {idx = x;return true;}
                if (ans < num) x++;
                else break;;
            }
            return false;
        }
        bool isPowerOfTwo_recursion(int num){
            if (num<1) return false;
            if (num==1){idx=0;return true;} 
            return loop(1,num);
        }
        bool isPowerOfTwo_bit1(int num){
            if (num<1) return false; // 结论,2的幂数,它和它减去1的数字相与为0
            if (!(num&(num-1))){
                char*s=new char();
                itoa(num,s,2);
                idx = string(s).size()-1;
                return true;
            } 
            return false;
        }
        bool isPowerOfTwo_bit2(int num){
            if (num<1) return false;
            if ((num&(-num))==num){// 结论,2的幂数,它和相反数相与为本身
                char*s=new char();
                itoa(num,s,2);
                idx = string(s).size()-1;
                return true;
            } 
            return false;
        }
        void printIdx(){cout<<"the idx is "<<idx<<endl;}
    protected:
    int idx=-1;
    bool loop(int x,int num){
        int ans =1;
        for(int i =0;i<x;i++)
            ans = ans * 2;
        if (ans == num) {idx=x;return true;}
        if (ans < num){loop(x+1,num);}
        return false;
    }
};
void _linearArray_twoOfPower(){
    linearArrayTwoOfPower solution;
    solution.isPowerOfTwo_iteration(32);
    cout<<"iteration=>\n";
    solution.printIdx();
    solution.isPowerOfTwo_recursion(128);
    cout<<"recursion=>\n";
    solution.printIdx();
    solution.isPowerOfTwo_bit1(1024);
    cout<<"bit1=>\n";
    solution.printIdx();
    solution.isPowerOfTwo_bit2(4096);
    cout<<"bit2=>\n";
    solution.printIdx();
}
#endif // !linearArrayTwoOfPower