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