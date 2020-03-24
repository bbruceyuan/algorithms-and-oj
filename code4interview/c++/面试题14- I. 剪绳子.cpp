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
    int cuttingRope(int n) {
        // 动态规划，不想使用 数学的那种推到
        vector<int> dp(n + 1, 0);
        dp[2] = 1;
        int tmp;
        for (std::size_t i = 3; i <= n; i++) {
            for (std::size_t j = 0; j < i; j++) {
                // 从 j 出
                tmp = std::max((i - j) * j, j * dp[i - j]);
                dp[i] = std::max(dp[i], tmp);
            }
        }
        return dp[n];
    }
};



int main() {
//    string s = "[1,2,3,null,null,4,5]";
    string s = "[5,2,3,null,null,2,4,3,1]";



//    string str = "hello world";
//    cout << s.find_last_not_of("world");

    return 0;
}