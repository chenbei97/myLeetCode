/*** 
 * @Author: chenbei
 * @Date: 2022-03-14 07:52:14
 * @LastEditTime: 2022-03-16 08:13:27
 * @Description: judge stone is jewel by iteration
 * @FilePath: \myLeetCode\characterString\charaterStringJewelsStones_Iteration.h
 * @A boy without dreams
 */
#ifndef charaterStringJewelsStonesIteration_
#define charaterStringJewelsStonesIteration_
#include  <string>
#include <unordered_set>
#include <iostream>
using namespace std;
class charaterStringJewelsStonesIteration{
public:
    int numJewelsInStones(string jewels, string stones) {
        int jewelsCount = 0;
        for (auto c : jewels){
            for (auto k:stones){
                if (c ==k)
                    jewelsCount++;
            }
        }
        return jewelsCount;
    }
};
void _charaterString_jewelsStones_iteration(){
    charaterStringJewelsStonesIteration solution;
    string jewels("aAFs");
    string stones("abcAABCDDefFsSa");
    int ans = solution.numJewelsInStones(jewels,stones);
    cout<<"iteration=> the jewel's number is "<<ans<<endl;
}
#endif // !charaterStringJewelsStonesIteration_