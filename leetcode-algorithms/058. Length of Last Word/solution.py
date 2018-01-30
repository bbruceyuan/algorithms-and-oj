#!/usr/bin/env python
# Created by Bruce yuan on 18-1-30.


class Solution:
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        return len(s.strip().split(' ')[-1])
