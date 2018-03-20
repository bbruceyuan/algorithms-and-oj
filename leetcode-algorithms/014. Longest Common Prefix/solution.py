#!/usr/bin/env python
# Created by BBruceyuan on 18-3-20.


class Solution:
    def longestCommonPrefix(self, strs):
        if len(strs) == 0:
            return ''
        ans = strs[0]
        for item in strs:
            while not item.startswith(ans):
                ans = strs[0][:len(ans) - 1]
        return ans

    @staticmethod
    def method(strs):
        if len(strs) == 0:
            return ''
        ans = ''
        for char in strs[0]:
            ans += char
            for item in strs:
                if not item.startswith(ans):
                    return ans[:len(ans) - 1]
        return ans


def main():
    s = Solution()
    ans = s.method(['a', 'b'])
    print(ans)


if __name__ == '__main__':
    main()
