class TreeNode:
     def __init__(self, x):
         self.val = x
         self.left = None
         self.right = None

class Solution:
    def countNodes(self, root: TreeNode) -> int:
        if not root: return 0
        level = 0
        node = root.left
        while node:  # 这里获得层数
            level += 1
            node = node.left
        l = 1<<level  # 左界
        r = (l<<1)-1  # 右界

        while l < r:
            mid = int((r+l+1)/2)  # 中位
            node = root
            path = 1<<(level-1)  # 取mid号数的后几位的模板
            while node and path > 0:
                if mid & path: node = node.right
                else: node = node.left
                path >>= 1  # 一层查完，查下一层
            if node: l = mid  # 存在left位置变化
            else: r = mid-1  # 不存在right位置变化
        return r  # 年轻人耗子尾汁
