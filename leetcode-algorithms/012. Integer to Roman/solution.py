#!/usr/bin/env python
# Created by BBruceyuan on 18-3-3.


class Solution:
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        values = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
        strs = ["M", "CM", "D", "CD",
                "C", "XC", "L", "XL",
                "X", "IX", "V", "IV", "I"]
        ans = []
        for i, item in enumerate(values):
            while num >= item:
                num -= item
                ans.append(strs[i])
        return ''.join(ans)
