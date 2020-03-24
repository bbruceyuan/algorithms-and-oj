#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>
using namespace std;


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rowLow = 0, rowHigh= matrix.size() -1, colLeft = 0, colRight =  matrix[0].size() -1;
        int i;
        std::vector<int> res;

        while (rowLow <= rowHigh && colLeft <= colRight) {
            //  从左往右
            for (i = colLeft; i <= colRight; i++) {
                res.push_back(matrix[rowLow][i]);
            }
            rowLow++;
            // 从上往下
            for (i = rowLow; i <= rowHigh; i++) {
                res.push_back(matrix[i][colRight]);
            }
            colRight--;

            // 从右往左
            for (i = colRight; i >= colLeft && rowLow <= rowHigh; i--) {
                res.push_back(matrix[rowHigh][i]);
            }
            rowHigh--;

            // 从下往上
            for (i = rowHigh; i >= rowLow && colLeft <= colRight; i--) {
                res.push_back(matrix[i][colLeft]);
            }
            colLeft++;
        }
        return res;
    }
};


template <typename T>
void print(const vector<T> &nums) {
    for (const auto & i: nums) {
        cout << i << ' ';
    }
    cout << endl;
}


int main() {
    Solution solution;
    vector<vector<int>> nums {{1, 2, 3, 4}, {5, 6, 7, 8},{9, 10, 11, 12}};

    auto a = solution.spiralOrder(nums);
    print(a);

    return 0;
}