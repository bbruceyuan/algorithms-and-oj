#!/usr/bin/env python
# Created by Bruce yuan on 18-2-7.


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def hasPathSum(self, root, sum):
        """
        这种情况看起来只能用DFS
        :type root: TreeNode
        :type sum: int
        :rtype: bool
        """
        if root is None:
            return False
        if root.left is None and root.right is None and root.val == sum:
            return True
        return self.hasPathSum(root.left, sum - root.val) or self.hasPathSum(root.right, sum - root.val)

    @staticmethod
    def dfs(root, sum_):
        if root is None:
            return False
        nodes = [root]
        while len(nodes) != 0:
            curr = nodes.pop()
            if curr.left is None and curr.right is None:
                if curr.val == sum_: return True
            if curr.left is not None:
                curr.left.val = curr.val + curr.left.val
                nodes.append(curr.left)
            if curr.right is not None:
                curr.right.val = curr.val + curr.right.val
                nodes.append(curr.right)
        return False
