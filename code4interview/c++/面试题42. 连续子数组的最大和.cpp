#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <iostream>
#include <sstream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // 连续数组最大和
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        for (std::size_t i = 1; i < nums.size(); i++) {
            if (dp[i -1] > 0) {
                dp[i] = dp[i -1] + nums[i];
            } else
                dp[i] = nums[i];
        }
        return *std::max_element(dp.begin(), dp.end());
    }
};



int main() {
//    string s = "[1,2,3,null,null,4,5]";
    string s = "[5,2,3,null,null,2,4,3,1]";



//    string str = "hello world";
//    cout << s.find_last_not_of("world");

    return 0;
}