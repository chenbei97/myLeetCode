import collections
from typing import List
class charaterStringSubdomainAccessCountHashTable:
    def subdomainVisits(self, cpdomains: List[str]) -> List[str]:
        ans = collections.Counter()
        for domain in cpdomains:
            count, domain = domain.split()
            count = int(count)
            frags = domain.split('.')
            for i in range(len(frags)):
                ans[".".join(frags[i:])] += count

        return ["{} {}".format(ct, dom) for dom, ct in ans.items()]
if __name__ == '__main__':
    cpdomains = ["9001 discuss.leetcode.com"]
    solution = charaterStringSubdomainAccessCountHashTable()
    print(solution.subdomainVisits(cpdomains))