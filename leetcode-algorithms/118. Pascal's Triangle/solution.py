#!/usr/bin/env python
# Created by Bruce yuan on 18-2-8.


class Solution:
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        if numRows == 0:
            return []
        ans = [[1]]
        for i in range(1, numRows):
            ans.append([1])
            for j in range(1, i):
                ans[i].append(ans[i - 1][j - 1] + ans[i - 1][j])
            ans[i].append(1)
        return ans

    @staticmethod
    def method_two(num):
        """
        用移位的方式，比如：
          1 1 0
        + 0 1 1
        ---------
          1 2 1
        :param num: 
        :return: 
        """
        if num == 0:
            return []
        ans = [[1]]
        for i in range(num - 1):
            ans.append([sum(item) for item in zip(ans[i] + [0], [0] + ans[i])])
        for i in ans:
            print(i)


if __name__ == '__main__':
    s = Solution()
    s.method_two(5)
    print(s.generate(6))
