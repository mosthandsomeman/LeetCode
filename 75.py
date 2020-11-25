from typing import List
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        idx = [nums.count(0),nums.count(1),nums.count(2)]
        nums.clear()
        nums.extend([0]*idx[0])
        nums.extend([2]*idx[1])
        nums.extend([2]*idx[2])