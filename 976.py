from typing import  List
import math
class Solution:
    def largestPerimeter(self, A: List[int]) -> int:
        A.sort(reverse= 1)
        res = 0
        print(A)
        for i in range(len(A) - 2):
            if A[i+1] + A[i+2] > A[i]:
                res = sum(A[i:i+3])
                break
        return res