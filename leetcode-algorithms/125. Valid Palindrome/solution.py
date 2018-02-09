#!/usr/bin/env python
# Created by Bruce yuan on 18-2-9.


class Solution:
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        head, tail = 0, len(s) - 1
        while head < tail:
            h_tmp, t_tmp = s[head].lower(), s[tail].lower()
            if not (h_tmp.isalpha() or h_tmp.isdecimal()):
                head += 1
            elif not (t_tmp.isalpha() or t_tmp.isdecimal()):
                tail -= 1
            else:
                if h_tmp != t_tmp:
                    return False
                head += 1
                tail -= 1
        return True


if __name__ == '__main__':
    s = Solution()
    print(s.isPalindrome('ab'))

