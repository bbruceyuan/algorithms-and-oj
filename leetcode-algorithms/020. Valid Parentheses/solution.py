#!/usr/bin/env python
# Created by BBruceyuan on 18-2-19.


class Solution:
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = []
        dict_ = {"]": "[", "}": "{", ")": "("}
        for char in s:
            if char in dict_.values():
                stack.append(char)
            elif char in dict_.keys():
                if stack == [] or dict_[char] != stack.pop():
                    return False
            else:
                return False
        return stack == []
