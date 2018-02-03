#!/usr/bin/env python
# Created by Bruce yuan on 18-2-2.
# Definition for singly-linked list.


class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def reverse_list(self, head, m, n):
        """
        需要一个头结点，因为加入需要从第一个开始，我们就需要记录前面那个一个节点
        """
        if head is None:
            return None
        dummy = ListNode(0)
        dummy.next = head
        pre = dummy
        for _ in range(m - 1):
            pre = pre.next

        start = pre.next
        then = pre.next.next

        for _ in range(n - m):
            start.next = then.next
            then.next = pre.next
            pre.next = then
            then = start.next
        return dummy.next
