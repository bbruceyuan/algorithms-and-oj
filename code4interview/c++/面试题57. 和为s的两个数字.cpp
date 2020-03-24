#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <iostream>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        std::size_t left = 0, right = nums.size() -1;
        while (left < right) {
            if (nums[left] + nums[right] == target) {
                res.push_back(nums[left]);
                res.push_back(nums[right]);
                break;
            } else if (nums[left] + nums[right] > target) {
                right--;
            } else {
                left++;
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    return 0;
}