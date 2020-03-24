#include <string>
#include <vector>
#include <queue>
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
    vector<int> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        std::queue<TreeNode*> nodes;
        std::vector<int> res;

        nodes.push(root);
        TreeNode* cur;
        while (!nodes.empty()) {
            cur = nodes.front();
            nodes.pop();

            //
            res.push_back(cur->val);
            if (cur->left) {
                nodes.push(cur->left);
            }
            if (cur->right) {
                nodes.push(cur->right);
            }
        }
        return res;
    }

};

int main() {
    Solution solution;
    return 0;
}