#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include<cmath>
#include <set>
using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int count{0};

        merge_merge(nums, 0, nums.size() -1, count);
        for (auto item: nums) {
            cout << item << '\t';
        }
        return count;
    }

    void merge_merge(vector<int> &a, int left, int right, int & count) {
        if (left >= right)
            return;
        int mid = left + (right - left ) /2;

        merge_merge(a, left, mid, count);
        merge_merge(a, mid +1, right, count);
        merge(a, left, mid, mid +1, right, count);
    }

    void merge(vector<int> &a, int l1, int r1, int l2, int r2, int &count) {
        vector<int> tmp;
        int l1_tmp = l1, l2_tmp = l2;
        while (l1 <= r1 && l2 <= r2) {
            if (a[l1] > a[l2]) {
                tmp.push_back(a[l2]);
                count += (r1 - l1 + 1);
                l2++;
            } else {
                tmp.push_back(a[l1]);
                l1++;
            }
        }
        while (l2 <= r2) {
            tmp.push_back(a[l2]);
            l2++;
        }

        while (l1 <= r1) {
            tmp.push_back(a[l1]);
            l1++;
        }


        for (std::size_t i = l1_tmp, idx=0; i <= r2; i++){
            a[i] = tmp[idx++];

        }
    }


};


class Solution2 {
public:
    int global_count = 0;
    int reversePairs(vector<int>& nums) {
        vector<int> copyarr(nums.size(), 0);
        merge_sort(nums, copyarr, 0, nums.size()-1);
        return global_count;
    }

    void merge_sort(vector<int>& nums, vector<int>& copyarr, int left, int right) {
        if (left >= right) return;
        int mid = (left+right) / 2;
        merge_sort(nums, copyarr, left, mid);
        merge_sort(nums, copyarr, mid+1, right);
        int i = left, j = mid+1, k = left;
        while (i <= mid && j <= right) {
            if (nums[j] < nums[i]) {
                copyarr[k++] = nums[j++];
                global_count += (mid-i+1);         // 关键点，也是归并排序添加的唯一一行代码。
            } else {
                copyarr[k++] = nums[i++];
            }
        }
        if (i <= mid) copy(nums.begin()+i, nums.begin()+mid+1, copyarr.begin()+k);
        if (j <= right) copy(nums.begin()+j, nums.begin()+right+1, copyarr.begin()+k);
        copy(copyarr.begin()+left, copyarr.begin()+right+1, nums.begin()+left);
    }
};


int main() {
    vector<int> a {7,5,8,6,4};
    vector<int> b {7,5,8,6,4};
    Solution s;
    Solution2 solution;
    auto ss = s.reversePairs(a);
    cout << endl << ss << endl;
    cout << solution.reversePairs(b);
    return 0;
}