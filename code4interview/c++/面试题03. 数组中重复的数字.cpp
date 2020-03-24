#include <iostream>
#include <utility>
#include <vector>
#include <unordered_map>
using namespace std;

// 每次都可以先自己定义一个 MyException
class MyException: public exception {
public:
    std::string s;
    explicit MyException(std::string str): s(std::move(str)) {};
    const char* what() const noexcept override {return s.c_str();};
};



class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for (std::size_t i = 0; i < nums.size(); i++) {
            while (nums[i] != i) {
                if (nums[nums[i]] != nums[i])
                    std::swap(nums[i], nums[nums[i]]);
                else
                    return nums[i];
            }
        }
        // 如果满足题目要求，这里不会到达
        // throw MyException("不能运行到这里");
        return -1;
    }

    int findRepeatNumber2(vector<int>& nums) {
        // 可以直接使用 hash map
        unordered_map<int, bool> m;
        for (auto i: nums) {
            if (m.find(i) == m.end()) {
                m[i] = true;
            } else
                return i;
        }
        throw MyException("不可能到达这里");
    }
};

int main() {
    vector<int> nums {0, 2, 2};
    cout << Solution::findRepeatNumber(nums) << endl;
    cout << Solution::findRepeatNumber2(nums) << endl;
    return 0;
}