#!/usr/bin/env python
# Created by BBruceyuan on 18-2-26.


class Solution:
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        roman = {'M': 1000,
                 'D': 500,
                 'C': 100,
                 'L': 50,
                 'X': 10,
                 'V': 5,
                 'I': 1
                 }
        z = 0
        for i in range(0, len(s) - 1):
            if roman[s[i]] < roman[s[i+1]]:
                z -= roman[s[i]]
            else:
                z += roman[s[i]]
        # 加上单位
        return z + roman[s[-1]]
