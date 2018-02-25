#!/usr/bin/env python
# Created by BBruceyuan on 18-2-25.


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def invertTree(self, root):
        """
        这个问题其实还是很好解决的
        :type root: TreeNode
        :rtype: TreeNode
        """
        if root is None:
            return None
        left = self.invertTree(root.left)
        right = self.invertTree(root.right)
        root.right = left
        root.left = right
        return root
