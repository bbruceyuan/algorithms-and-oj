#!/usr/bin/env python
# Created by Bruce yuan on 18-1-31.


class Solution:
    def isPalindrome(self, x):
        """
        如果直接将数字翻转，就可能出现数字溢出,所以不能直接翻转，只能翻转一半
        但是需要考虑到如果是个位数，就没法判断了
        :type x: int
        :rtype: bool
        """
        if x < 0 or (x % 10 == 0 and x != 0):
            return False
        m = 0
        # 至于为什么能考虑到如果后面是一个零的情况，那是因为测试用例
        while x > m:
            tmp = x % 10
            m = m * 10 + tmp
            x = x // 10
            print(m)
            print(x)
        return x == m or x == m // 10


if __name__ == '__main__':
    solution = Solution()
    print(solution.isPalindrome(1000))
