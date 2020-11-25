from typing import List
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        row, col = set(), set()
        c1, c2 = len(matrix), len(matrix[0])
        for i in range(len(matrix)):
            for j in range(len(matrix[i])):
                if matrix[i][j] == 0:
                    row.add(i)
                    col.add(j)
        for i in row:
            matrix[i] = [0]*c2
        for i in col:
            for j in range(len(matrix)):
                matrix[j][i] = 0