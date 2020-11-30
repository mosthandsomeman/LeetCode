from typing import List
import  math
class Solution:
    def maxTurbulenceSize(self, arr: List[int]) -> int:
        if len(arr) <= 1: return len(arr)
        res = 0
        dp = [[1]*2  for i in range(len(arr))]
        for i in range(1, len(arr)):
            if(arr[i] > arr[i-1]):
                dp[i][0] = dp[i-1][1] + 1
            if(arr[i] < arr[i-1]):
                dp[i][1] = dp[i-1][0] + 1
            res = max(res, max(dp[i]))
        return res

ob = Solution()
print(ob.maxTurbulenceSize([9,4,2,10,7,8,8,1,9]))