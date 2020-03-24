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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        vector<vector<int>> res;
        int level(1);
        // 试试 decltype 的用法，以下和 queue<TreeNode*> 是一样的
        std::queue<std::pair<int, decltype(root)>> nodes;
        nodes.push(std::make_pair(level, root));
        std::pair<int, TreeNode*> p;
        while (!nodes.empty()) {
            p = nodes.front();
            nodes.pop();
            if (res.size() < p.first) {
                // TODO: 这个用法待学习，只是根据ide 提示修改的
                // 这里等同于 res.push_back({});
                res.emplace_back();
            }
            res[p.first -1].push_back(p.second->val);

            if (p.second->left) {
                nodes.push(std::make_pair(p.first + 1, p.second->left));
            }
            if (p.second->right) {
                nodes.push(std::make_pair(p.first + 1, p.second->right));
            }
        }
        return res;
    }

};

int main() {
    Solution solution;

    vector<vector<int>> matrix;
    cout << matrix.size() << endl;
    matrix.push_back({});
    cout << matrix.size() << endl;
    cout << matrix[0].size() << endl;
    return 0;
}