#!/usr/bin/env python
# Created by Bruce yuan on 18-2-13.


class Solution:
    def convertToTitle(self, n):
        """
        :type n: int
        :rtype: str
        """
        ans = ''
        while n > 0:
            ans = chr((n-1) % 26 + 65) + ans
            n = (n - 1) // 26
        return ans


if __name__ == '__main__':
    s = Solution()
    print(s.convertToTitle(1))
