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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        // 看一下左子树和由子树的 高度
        int flag = calculate(root);
        return flag == -1;
    }

    int calculate(TreeNode *root) {
        if (root == nullptr) return 0;
        int left = calculate(root->left);
        if (left == -1) return -1;
        int right = calculate(root->right);
        if (right == -1) return -1;
        // 这是一个后序遍历
        int res;
        if (std::abs(right - left) > 1)
            res = -1;
        else
            res = std::max(right, left) + 1;
        return res;
    }

    bool isBalancedRecursive (TreeNode *root) {
        if (root == nullptr) return true;

        if (std::abs(calculateHeight(root->left) - calculateHeight(root->right)) > 1) return false;
        return isBalancedRecursive(root->right) && isBalancedRecursive(root->left);
    }

    int calculateHeight(TreeNode *root) {
        if (root == nullptr) return 0;
        int a = std::max(calculateHeight(root->left), calculateHeight(root->right));
        return a+1;
    }
};

int main() {
    Solution solution;
    return 0;
}