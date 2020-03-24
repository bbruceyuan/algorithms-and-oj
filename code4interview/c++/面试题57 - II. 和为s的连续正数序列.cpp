#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>
#include <limits>
using namespace std;

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        deque<int> tmp;
        int left = 1, sum = 1, right;
        tmp.push_back(left);

        for (int i = 2; i < target; i++) {
            right = i;
            sum = sum + right;
            tmp.push_back(right);
            while (sum > target && left < right) {
                sum -= left; // sum 要先减去左边那个
                left = left + 1;

                tmp.pop_front();
            }

            if (sum == target) {
                res.emplace_back(tmp.begin(), tmp.end());
            }
        }

        return res;
    }
};

int main() {
    Solution solution;
    auto res = solution.findContinuousSequence(9);
    for (const auto &item: res) {
        for (const auto &i: item) {
            cout << i << '\t';
        }
        cout << '\n' << endl;
    }

    return 0;
}