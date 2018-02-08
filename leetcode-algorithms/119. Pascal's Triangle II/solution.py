#!/usr/bin/env python
# Created by Bruce yuan on 18-2-8.


# 这题大坑，input是index，而不是逻辑位置
class Solution:
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        if rowIndex == 0:
            return [1]
        ans = [0] * (rowIndex + 1)
        ans[0] = 1
        for i in range(1, rowIndex + 1):
            for j in range(i, 0, -1):
                ans[j] = ans[j] + ans[j -1]
        return ans


if __name__ == '__main__':
    s = Solution()
    print(s.getRow(5))
