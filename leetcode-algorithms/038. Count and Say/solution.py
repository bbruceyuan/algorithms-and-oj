#!/usr/bin/env python
# Created by Bruce yuan on 18-1-25.


class Solution:
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        s = '1'
        for _ in range(n - 1):
            num, tmp_str, count = s[0], '', 0
            for char in s:
                if num == char:
                    count += 1
                else:
                    tmp_str += str(count) + num
                    num = char
                    count = 1
            tmp_str += str(count) + char
            s = tmp_str
        return s


def main():
    a = Solution()
    result = a.countAndSay(4)
    print(result)

if __name__ == '__main__':
    main()