#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int res(1);

        helper(root, res, 1);
        return res;
    }

    void helper(TreeNode* cur, int& res, int level) {
        // 和中序遍历算法一样，就不写非递归了。写了很多遍了。
        // 如果有要求再说吧
        if (cur == nullptr) return;
        if (level > res) res = level;
        if (cur->left) helper(cur->left, res, level + 1);
        if (cur->right) helper(cur->right, res, level + 1);
    }
};


int main() {
    Solution solution;
    return 0;
}