#!/usr/bin/env python
# Created by Bruce yuan on 18-2-7.


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def averageOfLevels(self, root):
        """
        :type root: TreeNode
        :rtype: List[float]
        """
        if root is None:
            return [0]
        import queue
        import functools
        q = queue.Queue()
        q.put(root)
        ans = []
        while not q.empty():
            tmp = []
            for _ in range(q.qsize()):
                node = q.get()
                tmp.append(node.val)
                if node.left is not None:
                    q.put(node.left)
                if node.right is not None:
                    q.put(node.right)
            average = functools.reduce(lambda x, y: x + y, tmp) / len(tmp)
            ans.append(average)
        return ans
