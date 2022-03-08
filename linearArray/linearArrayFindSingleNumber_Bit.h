#ifndef linearArrayFindSingleNumberBit_
#define linearArrayFindSingleNumberBit_
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
class linearArrayFindSingleNumberBit{
    public:
        int singleNumber(vector<int>& nums){
            int ans = 0;
            for (int i = 0; i < 32; ++i) { // 32位进制
                int total = 0; // 计算每个位号i,在该位置上所有1加起来的数
                for (int num: nums) {
                    total += ((num >> i) & 1);//右移i位相当于对num除2的i次方,余数就是位数
                    // 然后让余数和00..01作位运算,0的个数取决于对齐余数的位需要的0个数
                    // 例如110和1位运算,就相当于110和001运算,也就是只累积余数的最后1位
                    // 和1位运算是为了得到这个位是0还是1,不然num>>i是个10进制数不是2进制
                }
                if (total % 3) { // 余数是答案第i位的数字,非0即1,如果是1的话数字就可以扩大
                    ans |= (1 << i);//或等于,例如ans=3,也就是11,1<<2,就是100,也就是011和100或等于111
                    //从低位开始乘2^i,并累加,就是2进制=>10进制的方法
                    // 乘2^i就是和1<<i进行或运算
                }
            }
            return ans;
    }
};
void _linearArray_findSingleNumber_bit(){
    linearArrayFindSingleNumberBit solution;
    vector<int> nums={3,2,3,5,5,3,2,5,2,1000,1000,1000,7};
    int ans = solution.singleNumber(nums);
    cout<<"109d = 1101101b 109 >>0 => 109 >> 7 as follows\n";
    for(int i =0;i<7;i++){
        //cout<<(109>>i)<<" "; //109 54 27 13 6 3 1
        cout<<((109>>i)&1)<<" "; // 输出1011011 因为是低位先计算倒过来看1101101
    }
    cout<<"\n";
    cout<<"3/(1<<1) = "<<(3|(1<<2))<<endl;
    cout<<"bit=> the single number is "<<ans<<endl;
}
#endif // !linearArrayFindSingleNumberBit_