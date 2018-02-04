#!/usr/bin/env python
# Created by Bruce yuan on 18-2-4.


class Solution:
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 1 or n == 0:
            return n
        a, b = 1, 2
        for _ in range(2, n):
            tmp = a + b
            a = b
            b = tmp
            # a, b = b, a + b  # 效果是一样的，实际上也用了一个额外的空间
        return b

    def dynamic_method(self, n):
        """
        和上面用斐波那契数列方法本质是一样的
        :param n: 
        :return: 
        """
        if n == 0 or n == 1:
            return n
        a = [1, 2]
        for i in range(2, n):
            a.append(a[i - 1] +  a[i - 2])
        return a[-1]

    def recursive_method(self, n):
        """
        这个方法超时了
        :param n: 
        :return: 
        """
        if n == 1 or n == 0:
            return n
        if n ==  2:
            return 2
        # 这个竟然超时了
        return self.climbStairs(n - 1) + self.climbStairs(n - 2)