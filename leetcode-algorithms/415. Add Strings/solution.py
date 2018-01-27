#!/usr/bin/env python
# Created by Bruce yuan on 18-1-27.


class Solution:
    def addStrings(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        carry = 0
        result = []
        num1, num2 = list(num1), list(num2)
        while len(num2) > 0 or len(num1) > 0:
            n1 = int(num1.pop()) if len(num1) > 0 else 0
            n2 = int(num2.pop()) if len(num2) > 0 else 0
            tmp = n1 + n2 + carry
            result.append(tmp % 10)
            carry = tmp // 10
        if carry == 0:
            result.append(carry)
        return ''.join(str(x) for x in result[::-1])
