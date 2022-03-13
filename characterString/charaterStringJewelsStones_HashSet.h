#ifndef charaterStringJewelsStonesHashSet_
#define charaterStringJewelsStonesHashSet_
#include  <string>
#include <unordered_set>
#include <iostream>
using namespace std;
class charaterStringJewelsStonesHashSet{
public:
    int numJewelsInStones(string jewels, string stones) {
        int jewelsCount = 0;
        unordered_set<char> jewelsSet;
        int jewelsLength = jewels.length(), stonesLength = stones.length();
        for (int i = 0; i < jewelsLength; i++) { // 遍历宝石将其送入哈希集合
            char jewel = jewels[i];
            jewelsSet.insert(jewel); //insert可以指定单元素也可以是一批元素
        }
        for (int i = 0; i < stonesLength; i++) {
            char stone = stones[i];
            if (jewelsSet.count(stone)) { // 如果这个字符在哈希集合说明是宝石
                jewelsCount++;
            }
        }
        return jewelsCount;
    }
};
void _charaterString_jewelsStones_hashSet(){
    charaterStringJewelsStonesHashSet solution;
    string jewels("aAFs");
    string stones("abcAABCDDefFsSa");
    int ans = solution.numJewelsInStones(jewels,stones);
    cout<<"hashSet=> the jewel's number is "<<ans<<endl;
}
#endif // !charaterStringJewelsStonesHashTable_