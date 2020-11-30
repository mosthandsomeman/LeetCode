from typing import List
import heapq
import collections

class Solution:
    def reorganizeString(self, S: str) -> str:
        cnt = collections.Counter(S)
        res = ""
        if max(cnt.values()) > (len(S) + 1) // 2: return res
        hp = []
        for key, val in cnt.items():
            heapq.heappush(hp, (-val, key))
        pre = (0, None)
        while hp:
            v,k = heapq.heappop(hp)
            res += k
            if pre[0] < 0:
                heapq.heappush(hp, pre)
            pre = (v+1, k)
        return  res

ob = Solution()
print(ob.reorganizeString("jdajdhkdadld"))
