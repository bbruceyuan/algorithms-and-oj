#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>
using namespace std;


class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        // 使用动态规划，那么算法很简单，用一个二维数组

        int rowIdx= int(grid.size()), colIdx = int(grid[0].size());

        vector<vector<int>> dp(rowIdx, vector<int>(colIdx, 0));

        dp[0][0] = grid[0][0];
        // 初始化第一行，相当于假设只有一行
        // 只能往右遍历
        for (std::size_t i = 1; i < colIdx; i++)
            dp[0][i] = dp[0][i-1] + grid[0][i];
        // 只能往 下遍历
        for (std::size_t i = 1; i < rowIdx; i++)
            dp[i][0] += dp[i -1][0] + grid[i][0];
        for (std::size_t i = 1; i < rowIdx; i++) {
            for (std::size_t j = 1; j < colIdx; j++) {
                dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[rowIdx -1][colIdx -1];
    }
};


int main() {
    Solution solution;
    vector<int> a{6,5};
//    vector<int> c(a.begin() + 3, a.end() -1);
//    for (auto i: c) {
//        cout << i << '\t';
//    }
    return 0;
}