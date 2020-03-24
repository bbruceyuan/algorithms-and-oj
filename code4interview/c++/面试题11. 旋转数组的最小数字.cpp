#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int minArray(vector<int>& numbers) {
        // 假设 数组为 5 4 1 2 3
        if (numbers.empty()) return 0;
        if (numbers.size() == 1) return numbers[0];
        int left = 0, right = numbers.size() -1;
        int mid;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (numbers[mid] > numbers[right]) {
                left = mid + 1;
            } else if (numbers[mid] < numbers[right]) {
                right = mid;
            } else {
                right = right - 1;
            }
        }
        return numbers[left];
    }

    int minArray2(vector<int> &nums) {
        if (nums.empty()) return 0;
        return minArrayRecursive(nums, 0, nums.size() -1);
    }

    int minArrayRecursive(vector<int> &nums, int left, int right) {
        if (left == right) return nums[left];
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[right]) {
            return minArrayRecursive(nums, mid + 1, right);
        } else if (nums[mid] == nums[right]) {
            return minArrayRecursive(nums, left, right -1);
        } else {
            return minArrayRecursive(nums, left, mid);
        }
    }
};


int main () {
    Solution solution;
    vector<int> nums {3, 1, 3};

    cout << solution.minArray2(nums) << endl;
    return 0;
}