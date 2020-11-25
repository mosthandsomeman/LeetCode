from typing import List

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        for i in range(len(nums) - 1):
            j = i + 1
            while j < len(nums) and nums[i] == nums[j]:
                del nums[j]
        return len(nums)



def main():
    a = [1,1,2,2,3,3,3,4,4,5]
    A = Solution
    print(A.removeDuplicates(A, a))


if __name__ == '__main__':
    main()