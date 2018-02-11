#!/usr/bin/env python
# Created by Bruce yuan on 18-2-11.
"""
这题我竟然一下就想到了用双指针，太奇怪了吧。
是因为以前做题还有点印想？
"""

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if head is None:
            return False
        slow, fast = head, head
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
            if slow.val == fast.val:
                return True
        return False
