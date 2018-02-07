#!/usr/bin/env python
# Created by Bruce yuan on 18-2-6.


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if root is None:
            return []
        import queue
        q = queue.Queue()
        q.put(root)
        result = []
        while not q.empty():
            tmp = []
            for _ in range(q.qsize()):
                item = q.get()
                tmp.append(item.val)
                if item.left is not None:
                    q.put(item.left)
                if item.right is not None:
                    q.put(item.right)
            result.append(tmp)
        return result
