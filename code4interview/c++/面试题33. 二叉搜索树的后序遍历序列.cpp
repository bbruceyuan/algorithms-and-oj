#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>
using namespace std;


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        if (postorder.size() < 2) return true;
        // 思想，如果是二叉搜索树，那么 最后一个节点一定是
        int leftPartLen = 0;
        for (const auto &item: postorder) {
            if (item < postorder.back())
                leftPartLen += 1;
            else
                break;
        }
        vector<int> leftArr(postorder.begin(), postorder.begin() + leftPartLen);
        vector<int> rightArr(postorder.begin() + leftPartLen, postorder.end() - 1);

        for (const auto &item: rightArr) {
            if (item < postorder.back()) {
                return false;
            }
        }
        auto leftFlag = verifyPostorder(leftArr);
        auto rightFlag = verifyPostorder(rightArr);

        return leftFlag && rightFlag;
    }
};

int main() {
    Solution solution;
    vector<int> a{6,5};
    cout << solution.verifyPostorder(a) << endl;
//    vector<int> c(a.begin() + 3, a.end() -1);
//    for (auto i: c) {
//        cout << i << '\t';
//    }
    return 0;
}