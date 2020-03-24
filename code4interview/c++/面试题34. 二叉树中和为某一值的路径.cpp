#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (!root) return {};
        // 这题应该使用的是典型的 回溯法
        vector<vector<int>> res;
        int tmp = 0;
        vector<int> tmpRes;

        back(root, sum, res, tmp, tmpRes);
        return res;
    }

    void back (TreeNode *root, const int &sum, vector<vector<int>> &res, int &tmp, vector<int> tmpRes) {
        tmp += root->val;
        tmpRes.push_back(root->val);

        if (tmp == sum && root->left == nullptr && root->right == nullptr) {
            // 要求是和一样，且是子节点
            res.push_back(tmpRes);

            // 下面这三行可以有，也可以没有。
//            tmp -= root->val;
//            tmpRes.pop_back();
//            return;
        }

        if (root->left)
            back(root->left, sum, res, tmp, tmpRes);
        if (root->right)
            back(root->right, sum, res, tmp, tmpRes);

        tmp -= root->val;
        tmpRes.pop_back();
    }
};


int main() {
    Solution solution;
    vector<int> a{6,5};
//    vector<int> c(a.begin() + 3, a.end() -1);
//    for (auto i: c) {
//        cout << i << '\t';
//    }
    return 0;
}