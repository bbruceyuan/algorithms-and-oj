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
    int kthLargest(TreeNode* root, int k) {
        if (root == nullptr) return 0;
        int count = 0;
        auto res(0);
        inOrder(root, count, k, res);
        return res;
    }

    void inOrder(TreeNode* root, int &count, const int & k, int & res) {
        if (root == nullptr) return ;
        if (root->right)
            inOrder(root->right, count, k, res);
        count += 1;
        if (count == k) {
            res = root->val;
            return ;
        }
        if (root->left)
            inOrder(root->left, count, k, res);
    }

    int kthLargest2(TreeNode* root, int k) {
        // 使用 中序遍历非递归
        if (root == nullptr) return 0;
        int count = 0;
        auto res(0);

        std::stack<TreeNode *> nodes;
        auto cur = root;
        while (!nodes.empty() || cur) {
            while (cur) {
                nodes.push(cur);
                cur = cur->right;
            }
            cur = nodes.top();
            nodes.pop();

            count += 1;
            if (count == k) {
                res = cur->val;
                break;
            }
            cur = cur->left;
        }

        return res;
    }



};

int main() {
    Solution solution;
    return 0;
}