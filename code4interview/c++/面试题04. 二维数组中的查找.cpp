#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        // 直接暴力遍历每一个数字
        bool flag = false;
        for (const auto& v: matrix) {
            // v 是一个 arr
            for (const auto& i: v) {
                if (i == target) {
                    flag = true;
                }
            }
        }
        return flag;

    }
    bool findNumberIn2DArray2(vector<vector<int>> &matrix, int target) {
        // 这这个使用 数组规律做题
        if (matrix.empty()) return false;
        int colIdx = 0, rowIdx = int(matrix.size()) - 1;
        while (colIdx < matrix[0].size() && rowIdx >= 0) {
            if (matrix[rowIdx][colIdx] == target) {
                return true;
            } else if (matrix[rowIdx][colIdx] > target) {
                rowIdx--;
            } else {
                colIdx++;
            }
        }
        return false;
    }

    int findNumberIn2DArray3(vector<vector<int>> &matrix, int target) {
        // 还可以使用二分法做题
        // 这种方法其实并不建议
        // TODO: 需要 Debug

        if (matrix.empty() or matrix[0].empty())
            return false;

        int low = 0, high = int(matrix.size()) -1;
        int mid;
        while (low < high) {
            mid = low + (high - low + 1) / 2;
            if (matrix[mid][0] > target)
                high = mid -1;
            else
                low = mid;
        }
        int rowIdx = low;
        int left = 0, right = (int)matrix[0].size() -1;
        while (left < right) {
            mid = left + (right - left + 1) / 2;
            if (matrix[rowIdx][mid] > target) {
                right = mid -1;
            } else
                left = mid;
        }
        // 这个时候 left 一定等于 right
        return matrix[rowIdx][left] == target;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> nums {
            {1,   4,  7, 11, 15},
            {2,   5,  8, 12, 19},
            {3,   6,  9, 16, 22},
            {10, 13, 14, 17, 24},
            {18, 21, 23, 26, 30}};

//    vector<vector<int>> nums;
//    cout << solution.findNumberIn2DArray(nums, 9) << endl;
//    cout << solution.findNumberIn2DArray2(nums, 3) << endl;
    cout << solution.findNumberIn2DArray3(nums, 5) << endl;
    return 0;
}