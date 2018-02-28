#!/usr/bin/env python
# Created by BBruceyuan on 18-2-28.


class Solution:
    def rotate(self, matrix):
        """
        具体做法可以查看一下我在js文件中的解释
        
        这里我是先直接reverse，然后转置一下
        
        这题不需要return anything
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        matrix.reverse()
        for i in range(len(matrix)):
            for j in range(i + 1, len(matrix)):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
