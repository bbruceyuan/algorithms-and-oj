#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>
#include <limits>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 从前往后遍历 保存最小的
        // TODO: 从后往前遍历记录最大的。留给读者的作业
        if (prices.size() <= 1) return 0;
        int curMin = prices[0], res = 0;

        for (std::size_t i = 1; i < prices.size(); i++) {
            res = std::max(res, prices[i] - curMin);
            curMin = std::min(prices[i], curMin);
        }
        return res;
    }
};

int main() {
    Solution solution;

    return 0;
}