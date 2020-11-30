from typing import List
class Solution:
    def fourSumCount(self, A: List[int], B: List[int], C: List[int], D: List[int]) -> int:
        idx = {}
        cnt = 0
        for i in range(len(A)):
            for j in range(len(B)):
                if A[i]+B[j] in idx:
                    idx[A[i]+B[j]].append((i,j))
                else:
                    idx[A[i] + B[j]] = [(i, j)]
        for i in range(len(C)):
            for j in range(len(D)):
                if -(C[i]+D[j]) in idx:
                    cnt += len(idx[-(C[i] + D[j])])
        return cnt

a = Solution()
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]
print(a.fourSumCount(A,B,C,D))