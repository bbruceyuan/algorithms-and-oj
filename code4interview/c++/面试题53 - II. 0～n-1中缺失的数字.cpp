#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>
#include <limits>
using namespace std;


class Solution {
public:
    int missingNumber(vector<int> &nums) {
        // 题目，排序，应该使用二分
        int left = 0, right = nums.size() -1;
        int mid, res = 0;
        while (left <= right) {
            // 如果
            mid = left + (right - left) / 2;
            if (nums[mid] == mid) {
                left = mid + 1;
            } else {
                right = mid -1;
            }
        }
        if (left >= nums.size()) return left;
        if (nums[left] != left)
            res = left;
        return res;
    }


    int missingNumber2(vector<int>& nums) {
        // 可以使用最傻比的方法，一次遍历
        int res = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i) {
                res = i;
                break;
            }
        }
        return res;
    }
};
int main() {
    Solution solution;

    return 0;
}