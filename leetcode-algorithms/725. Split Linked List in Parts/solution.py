#!/usr/bin/env python
# Created by Bruce yuan on 18-1-25.

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution(object):
    def splitListToParts(self, root, k):
        """
        :type root: ListNode
        :type k: int
        :rtype: List[ListNode]
        """
        # reminder 余数
        min_width, reminder = self.__count_and_div(root, k)
        result = []
        for i in range(k):
            if i < reminder:
                tmp, root = self.__build_list(root, min_width + 1)
                result.append(tmp)
            else:
                tmp, root = self.__build_list(root, min_width)
                result.append(tmp)
        return result

    @staticmethod
    def __count_and_div(root, k):
        count = 0
        while root:
            count += 1
            root = root.next
        return divmod(count, k)

    @staticmethod
    def __build_list(curr, length):
        """
        构建链表,这里是根据原来的链表构建的，而不是新建一个链表
        :param curr: 当前节点
        :param length: 构建链表的长度
        :return: 返回头结点（这里是指第一个节点
        """
        if length == 0 or curr is None:
            return None, None
        tmp = curr
        for i in range(length - 1):
            curr = curr.next
        next_head = curr.next
        curr.next = None
        return tmp, next_head
