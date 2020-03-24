#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <iostream>
using namespace std;


class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        int left = 0, right = (int)arr.size() -1;
        int pivotIdx;
        vector<int> res;
        while (left <= right) {
            pivotIdx = pivot(arr, left, right);

            if (pivotIdx == k -1) {
                res =  std::vector<int>(arr.begin(), arr.begin() + k);
                break;
            } else if (pivotIdx > k -1) {
                // 说明结果应该在 左边
                right = pivotIdx -1;
            } else {
                left = pivotIdx + 1;
            }
        }
        return res;
    }

    int pivot (vector<int> &arr, int left, int right) {
        int pivotValue = arr[right];
        auto pivotIdx = left -1;
        for (std::size_t i = left; i < right; i++) {
            if (arr[i] < pivotValue) {
                pivotIdx++;
                std::swap(arr[pivotIdx], arr[i]);
            }
        }
        // 下一个需要
        std::swap(arr[pivotIdx+ 1], arr[right]);
        return pivotIdx + 1;
    }
};


template <typename T>
void print(const vector<T> &nums) {
    for (const auto & i: nums) {
        cout << i << ' ';
    }
    cout << endl;
}


int main() {
    Solution solution;
    vector<int> nums{0,1,1,2,4,4,1,3,3,2};
    auto res = solution.getLeastNumbers(nums, 6);
//    auto res = solution.pivot(nums, 0, 4);
//    cout << res << endl;

    print(res);
    return 0;
}