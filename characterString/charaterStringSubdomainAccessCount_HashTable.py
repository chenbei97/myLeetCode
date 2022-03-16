'''
Author: chenbei
Date: 2022-03-14 07:52:14
LastEditTime: 2022-03-16 08:14:10
Description: subdomain access count by hashTable
FilePath: \myLeetCode\characterString\charaterStringSubdomainAccessCount_HashTable.py
A boy without dreams
'''
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