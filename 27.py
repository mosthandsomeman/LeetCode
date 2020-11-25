from typing import List

class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        cnt = 0
        for i in range(len(nums)):
            if nums[i] == val:
                cnt+=1
        while cnt > 0:
            nums.remove(val)
            cnt-=1
        return len(nums)

obj = Solution
obj.removeElement(obj, [1,2,2,3], 2)