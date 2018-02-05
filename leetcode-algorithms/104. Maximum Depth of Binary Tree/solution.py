#!/usr/bin/env python
# Created by Bruce yuan on 18-2-4.


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
            return 0
        return 1 + max(self.maxDepth(root.left), self.maxDepth(root.right))

    @staticmethod
    def method_two(root):
        if root is None:
            return 0
        import queue
        q = queue.Queue()
        q.put(root)
        count = 0
        # BFS 遍历
        while not q.empty():
            count += 1
            for _ in range(q.qsize()):
                item = q.get()
                # 下面两个都要判断
                if item.left is not None:
                    q.put(item.left)
                if item.right is not None:
                    q.put(item.right)
        return count

    @staticmethod
    def method_three(root):
        # DFS
        if root is None:
            return 0
        node = [root]
        value = [1]
        max_num = 0
        while len(node) != 0:
            item = node.pop()
            tmp = value.pop()
            max_num = max(tmp, max_num)
            if item.left is not None:
                node.push(item.left)
                value.push(tmp + 1)
            if item.right is not None:
                node.push(item.right)
                value.push(tmp + 1)
        return max_num
