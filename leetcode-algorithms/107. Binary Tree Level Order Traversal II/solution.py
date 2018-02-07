#!/usr/bin/env python
# Created by Bruce yuan on 18-2-6.


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrderBottom(self, root):
        """
        做了上面这个之后，竟然一次就过了2333，哈哈哈
        :type root: TreeNodes
        :rtype: List[List[int]]
        """
        if root == None:
            return []
        ans = []
        import queue
        q = queue.Queue()
        q.put(root)
        while not q.empty():
            tmp = []
            for _ in range(q.qsize()):
                item = q.get()
                tmp.append(item.val)
                if item.left is not None:
                    q.put(item.left)
                if item.right is not None:
                    q.put(item.right)
            ans.insert(0, tmp)
        return ans
