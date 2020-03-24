#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        if (nums.empty()) return {};
        // 注意的是如果使用了size_t 那么就需要考虑一下溢出问题
        // 第一种方法就可以使用双指针的方式
        std::size_t left = 0, right = nums.size() -1;

        while (left < right) {
            while (left < right && nums[right] %2 ==0) {
                right--;
            }
            while (left < right && nums[left] % 2 == 1) {
                left++;
            }
            std::swap(nums[left], nums[right]);
        }

        return nums;
    }

    vector<int> pivot(vector<int> &nums) {
        // 使用快速排序那种思想去做. 这种 partion 的方法叫做
        int left = -1;

        for (std::size_t i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 != 0) {
                left++;
                std::swap(nums[left], nums[i]);
            }
        }
        return nums;
    }
};


template <typename T>
void print(const vector<T> &nums) {
    for (const auto & item: nums) {
        cout << item << '\t';
    }
    cout << endl;
}

int main () {
    vector<int> nums = {2,1, 3, 4, 5};
    Solution s;
//    nums = s.exchange(nums);
    nums = s.pivot(nums);
    print(nums);
    return 0;
}