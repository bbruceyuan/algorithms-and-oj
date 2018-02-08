#!/usr/bin/env python
# Created by Bruce yuan on 18-2-7.


class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s:
            return 0
        tmp = {}
        max_ = 0
        start = 0
        for i in range(len(s)):
            # 如果开始是大于我们要的那个，其实没有意义了。不需要重新弄开始
            if s[i] in tmp and start <= tmp.get(s[i]):
                start = tmp.get(s[i]) + 1
            else:
                max_ = max(max_, i - start + 1)
            tmp[s[i]] = i
        return max_


def main():
    s = Solution()
    r = s.lengthOfLongestSubstring("pwwkew")
    print(r)


if __name__ == '__main__':
    main()
