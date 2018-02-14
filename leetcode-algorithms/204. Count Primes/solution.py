#!/usr/bin/env python
# Created by Bruce yuan on 18-2-14.


import math


class Solution:
    def countPrimes(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n <= 2:
            return 0
        res = [True] * n
        res[0] = res[1] = False
        for i in range(2, n):
            if res[i] is True:
                for j in range(i, (n - 1) // i + 1):
                    res[i * j] = False
        return sum(res)

    def method(self, n):
        """
        这个方法竟然超时了，心累啊
        :param n: 
        :return: 
        """
        if n < 2:
            return 0
        count = 0
        for i in range(2, n):
            count += self.is_prime(i)
        return count

    @staticmethod
    def is_prime(n):
        for j in range(2, int(math.sqrt(n)) + 1):
            if n % j == 0:
                return 0
        return 1

if __name__ == '__main__':
    s = Solution()
    print(s.countPrimes(5))
