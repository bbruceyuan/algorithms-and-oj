#!/usr/bin/env python
# Created by Bruce yuan on 18-2-7.


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isBalanced(self, root):
        """
        这题需要注意的是，我们不可以只判断root.left和root.right高度之间的差距
        因为子树之间也还有可能不平衡
        :type root: TreeNode
        :rtype: bool
        """
        if root is None:
            return True
        return self.is_valid(root) != -1

    @classmethod
    def is_valid(cls, root):
        if root is None:
            return 0
        l = cls.is_valid(root.left)
        r = cls.is_valid(root.right)
        if abs(l - r) > 1 or l == -1 or r == -1:
            return -1
        return 1 + max(l, r)
