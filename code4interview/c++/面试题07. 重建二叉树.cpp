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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // 找到中止条件
        if (preorder.empty()) return nullptr;

        // 首先简历树的根节点
        auto root = new TreeNode(preorder[0]);
        // 下一步是获取 左子树的 preorder 和 inorder
        auto it = std::find(inorder.begin(), inorder.end(), preorder[0]);

        vector<int> leftInOrder(inorder.begin(), it);
        // 不能包括第一个数字
        vector<int> rightInOrder(it + 1, inorder.end());

        vector<int> leftPreOrder(preorder.begin() + 1, preorder.begin() + 1 + leftInOrder.size());
        vector<int> rightPreOrder(preorder.begin() + 1 + leftInOrder.size(), preorder.end());

        root->left = buildTree(leftPreOrder, leftInOrder);
        root->right = buildTree(rightPreOrder, rightInOrder);
        return root;
    }

    TreeNode* buildTreeNoRecursive(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return nullptr;
        stack<TreeNode*> roots;
        std::size_t pre = 0, in = 0;

        auto root = new TreeNode(preorder[pre]);
        auto returnRoot = root;
        roots.push(root);
        pre++;

        while (pre < preorder.size()) {
            if (root->val == inorder[in]) {
                while (!roots.empty() && roots.top()->val == inorder[in]) {
                    root = roots.top();
                    roots.pop();
                    in++;
                }
                root->right = new TreeNode(preorder[pre]);
                root = root->right;
                roots.push(root);
                pre++;
            } else {
                root->left = new TreeNode(preorder[pre]);
                root = root->left;
                roots.push(root);
                pre++;
            }
        }
        return returnRoot;
    }

};

int main() {
    Solution solution;
    vector<int> preorder{3,5, 9,10, 20,15,7}, inorder{9,5, 10, 3,15,20,7};
    solution.buildTreeNoRecursive(preorder, inorder);
    return 0;
}