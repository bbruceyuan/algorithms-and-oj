#!/usr/bin/env python
# created by BBruceyuan on 18-5-7


class Solution:
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        dic = {
            '2': 'abc',
            '3': 'def',
            '4': 'ghi',
            '5': 'jkl',
            '6': 'mno',
            '7': 'pqrs',
            '8': 'tuv',
            '9': 'wxyz'
        }
        a = [dic[x] for x in digits]
        from itertools import product  # 笛卡尔积
        res = list(''.join(x) for x in product(*a))
        return res if len(digits) != 0 else []


def main():
    s = Solution()
    print(s.letterCombinations(''))


if __name__ == '__main__':
    main()
