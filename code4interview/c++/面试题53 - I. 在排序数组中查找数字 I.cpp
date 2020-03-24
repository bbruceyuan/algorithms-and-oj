#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>
#include <limits>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return 0;
        int left = 0, right = int(nums.size() -1);
        int firstK = findFirstK(nums, target, 0, right);
        int secondK = findLastK(nums, target, 0, right);

        cout << firstK << '\t' << secondK << endl;

        int res = 0;
        if (firstK != -1 && secondK != -1) {
            res = secondK - firstK + 1;
        }
        return res;
    }

    int findFirstK (const vector<int> &nums, int target, int left, int right) {
        int mid, res=-1;
        while (left <= right) {
             mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] == target) {
                // 如果左边不是 target, 那么返回自己
                if ((mid > 0 && nums[mid -1] != target) || mid == 0) {
                    res = mid;
                    break;
                }
                else
                    right = mid -1;
            }
        }

        return res;
    }

    int findLastK (const vector<int>& nums, int target, int left, int right) {
        int mid, res = -1;
        auto tmp = right;

        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid -1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                if (mid == tmp || (mid < tmp && nums[mid + 1] != target)) {
                    res = mid;
                    break;
                } else {
                    left = mid + 1;
                }
            }
        }
        return res;
    }
};


int main() {
    Solution solution;
    vector<int> arr {5,7,7,8,8,10};
    auto res = solution.search(arr, 8);

    cout << res << endl;

    return 0;
}