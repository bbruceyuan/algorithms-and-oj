#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <iostream>
using namespace std;


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // 高级解法
        int count(1);
        int tmp = nums[0];
        for (std::size_t i = 1; i < nums.size(); i++) {
            if (tmp == nums[i])
                count++;
            else
                count--;
            if (count == 0) {
                tmp = nums[i];
                count += 1;
            }
        }
        return tmp;

    }
    int majorityElement2(vector<int>& nums) {
        // 使用 hash map
        unordered_map<int, int> m;
        for (const auto & item: nums) {
            cout << m[item] << endl;
            m[item]++;
            if (m[item] > nums.size() / 2) return item;
        }
        return 0;

    }
    int majorityElement3(vector<int>& nums) {
        // 使用 排序
        std::sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
};



int main() {
    Solution solution;
    vector<int> nums{1, 2, 3};
    solution.majorityElement2(nums);
    return 0;
}