class Solution:
    def sortString(self, s: str) -> str:
        idx = [0]*128
        res = ""
        for i in range(128):
            idx[i] = s.count(chr(i))
        while sum(idx) != 0:
            for i in range(128):
                if idx[i] != 0:
                    idx[i] -= 1
                    res += chr(i)

            for i in range(127,-1,-1):
                if idx[i] != 0:
                    idx[i] -= 1
                    res += chr(i)
        return res

obj = Solution()
print(obj.sortString("aaaaffffhhhhh"))