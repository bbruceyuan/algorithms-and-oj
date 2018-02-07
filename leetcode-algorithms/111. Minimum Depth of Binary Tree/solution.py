#!/usr/bin/env python
# Created by Bruce yuan on 18-2-7.


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        # BFS
        if root is None:
            return 0
        import queue
        q = queue.Queue()
        q.put(root)
        depth = 0
        while not q.empty():
            depth += 1
            for _ in range(q.qsize()):
                item = q.get()
                if item.left is not None:
                    q.put(item.left)
                if item.right is not None:
                    q.put(item.right)
                if item.left is None and item.right is None:
                    return depth
        return depth

    @staticmethod
    def dfs(root):
        """
        用可以用非递归的dfs来做吗？暂时没想到
        :param root: 
        :return: 
        """
        if root is None:
            return 0
        node = [root]
        pass

    def recurrent(self, root):
        """
        这个超级好理解。
        :param root: 
        :return: 
        """
        if root is None:
            return 0
        l = self.recurrent(root.left)
        r = self.recurrent(root.right)
        return l + r + 1 if l == 0 or r == 0 else min(l, r) + 1
