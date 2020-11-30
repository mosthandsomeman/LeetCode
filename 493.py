from typing import List
class Solution:
    def reversePairs(self, nums: List[int]) -> int:
        cnt = 0
        for i in range(len(nums)-1,-1,-1):
            tmp = [nums[j] for j in range(i) if nums[j] > 2 * nums[i]]
            cnt += len(tmp)
        return  cnt


ob = Solution()
print(ob.reversePairs([2,4,3,5,1]))