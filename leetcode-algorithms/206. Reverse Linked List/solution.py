#!/usr/bin/env python
# Created by Bruce yuan on 18-2-1.


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        pre = None
        while head:
            next_ = head.next
            head.next = pre
            pre = head
            head = next_
        return pre

    # 这里定义一个递归版本的
    # 需要两个节点,好像好好想想还是能理解的
    def reverse_list(self, node, prev=None):
        if not node:
            return prev
        n = node.next
        node.next = prev
        return self.reverse_list(n, node)
