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
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::deque<std::size_t > windows;
        vector<int> res;

        // 如果只有 ++, 那么可以使用 size_t
        for (std::size_t i = 0; i < nums.size(); i++) {
            while (!windows.empty() && nums[windows.back()] < nums[i]) {
                windows.pop_back();
            }
            windows.push_back(i);

            if (windows.front() + std::size_t(k) == i)
                windows.pop_front();
            if (i >= k -1)
                res.push_back(nums[windows.front()]);
        }
        return res;
    }
};

int main() {
    Solution solution;
    return 0;
}