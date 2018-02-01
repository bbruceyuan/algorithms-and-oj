#!/usr/bin/env python
# Created by Bruce yuan on 18-1-31.


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def isPalindrome(self, head):
        """
        这题我想不到怎么 O(1) space
        :type head: ListNode
        :rtype: bool
        """
        current = head
        count = 0
        while current:
            count += 1
            current = current.next
        if count == 1:
            return True
        # 把她重新用作中位数
        count = count // 2 if count % 2 == 0 else count // 2 + 1
        current = head
        for _ in range(count):
            current = current.next
        # 123 4 321  0 0
        current = self.reverse_list(current)
        # print(current.val)
        # print(head.val)
        while current and head:
            # print('test test')
            if current.val != head.val:
                return False
            current = current.next
            head = head.next
            # print(current)
            # print(head)
        return True

    @staticmethod
    def reverse_list(head):
        pre = None
        # 这就是头插法，竟然都忘记了。简直了
        while head:
            next_ = head.next
            head.next = pre
            pre = head
            head = next_
        return pre


def main():
    head = ListNode(0)
    next_ = ListNode(0)
    head.next = next_
    solution = Solution()
    result = solution.isPalindrome(head)
    print(result)


if __name__ == '__main__':
    main()
