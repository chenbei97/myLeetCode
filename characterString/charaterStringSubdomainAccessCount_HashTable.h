#ifndef charaterStringSubdomainAccessCountHashTable_
#define charaterStringSubdomainAccessCountHashTable_
#include  <string>
#include <unordered_map>
#include <iostream>
using namespace std;
class charaterStringSubdomainAccessCountHashTable{
    public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        // C++不好做,java的做法给出
        /*
        Map<String, Integer> counts = new HashMap();
        for (String domain: cpdomains) {
            String[] cpinfo = domain.split("\\s+");
            String[] frags = cpinfo[1].split("\\.");
            int count = Integer.valueOf(cpinfo[0]);
            String cur = "";
            for (int i = frags.length - 1; i >= 0; --i) {
                cur = frags[i] + (i < frags.length - 1 ? "." : "") + cur;
                counts.put(cur, counts.getOrDefault(cur, 0) + count);
            }
        }

        List<String> ans = new ArrayList();
        for (String dom: counts.keySet())
            ans.add("" + counts.get(dom) + " " + dom);
        return ans;
        */
        return vector<string>() ;
    }
};
void _charaterString_subdomainAccessCount_hashTable(){
    charaterStringSubdomainAccessCountHashTable solution;
}
#endif // !charaterStringSubdomainAccessCountHashTable_