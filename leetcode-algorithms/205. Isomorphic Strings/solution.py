#!/usr/bin/env python
# Created by Bruce yuan on 18-2-13.


class Solution:
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if len(s) != len(t):
            return False
        s_arr = [0] * len(s)
        t_arr = [0] * len(s)
        s_dict = {}
        t_dict = {}
        for i in range(len(s)):
            if s[i] in s_dict:
                s_arr[i] = s_dict[s[i]]
            else:
                s_arr[i] = i
                s_dict[s[i]] = i
            if t[i] in t_dict:
                t_arr[i] = t_dict[t[i]]
            else:
                t_arr[i] = i
                t_dict[t[i]] = i
        return s_arr == t_arr
