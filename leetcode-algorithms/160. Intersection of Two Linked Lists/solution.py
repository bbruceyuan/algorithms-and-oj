#!/usr/bin/env python
# Created by Bruce yuan on 18-2-12.


# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        len_a, len_b = self.get_length(headA), self.get_length(headB)
        while len_a < len_b:
            len_b -= 1
            headB = headB.next
        while len_a > len_b:
            len_a -= 1
            headA = headA.next
        while headA != headB:
            headA = headA.next
            headB = headB.next
        return headA

    @staticmethod
    def get_length(head):
        length = 0
        while head:
            length += 1
            head = head.next
        return length
