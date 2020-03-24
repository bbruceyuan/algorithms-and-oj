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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return helpSymmetric(root->left, root->right);
    }

    bool helpSymmetric(TreeNode *p, TreeNode *q) {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;
        if (q->val == p->val) {
            return helpSymmetric(q->left, p->right) && helpSymmetric(q->right, p->left);
        } else {
            return false;
        }
    }

};

int main() {
    Solution solution;
    return 0;
}