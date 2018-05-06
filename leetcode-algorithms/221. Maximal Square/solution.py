#!/usr/bin/env python
# created by BBruceyuan on 18-5-2


import numpy as np


class Solution:
    def maximalSquare(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        if len(matrix) == 0:
            return 0
        matrix = np.array(matrix)
        row, column = len(matrix), len(matrix[0])
        dp = np.zeros((row + 1, column + 1))
        print(dp)
        max_sqlen = 0
        for i in range(1, row + 1):
            for j in range(1, column + 1):
                if matrix[i - 1][j - 1] == '1':
                    dp[i][j] = min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]) + 1
                    max_sqlen = max(max_sqlen, dp[i][j])
        return int(max_sqlen ** 2)


def main():
    s = Solution()
    a = s.maximalSquare([["1","0","1","0","0"],
                         ["1","0","1","1","1"],
                         ["1","1","1","1","1"],
                         ["1","0","0","1","0"]])
    print(a)


if __name__ == '__main__':
    main()
