#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>
#include <limits>
using namespace std;

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        // 通过 某一位数是不是1 讲数字分成两个数组
        int tmp = nums[0];
        for (std::size_t i = 1; i < nums.size(); i++) {
            tmp = tmp ^ nums[i];
        }
        // 得到 单独出现的两个数字的 异或的值
        // 按照 第 N 未为 1 讲数组分成两部分
        vector<int> arr1, arr2;

        unsigned int flag = 1;
        while (true) {
            if (flag & tmp) break;
            flag = flag << 1;
        }

        for (auto &item: nums) {
            if (flag & item)
                arr1.push_back(item);
            else
                arr2.push_back(item);
        }

        vector<int> res;
        res.push_back(findSingle(arr1));
        res.push_back(findSingle(arr2));
        return res;
    }

    int findSingle (vector<int> &arr) {
        // 理论上使用 异或 的时候应该使用 无符号数字
        int res = arr[0];
        for (std::size_t i = 1; i < arr.size(); i++) {
            res = res ^ arr[i];
        }
        return res;
    }
};


int main() {
    Solution solution;
    vector<int> arr { 1,2,10,4,1,4,3,3};
    auto res = solution.singleNumbers(arr);
    for (auto item : res) {
        cout << item << '\t' ;
    }
    return 0;
}