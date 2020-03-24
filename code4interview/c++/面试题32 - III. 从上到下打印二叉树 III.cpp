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
    vector<vector<int>> levelOrder (TreeNode *root) {
        // 使用双端队列
        if (root == nullptr) return {};
        vector<vector<int>> res;
        bool flag = true;

        std::deque<TreeNode *> nodes;
        nodes.push_back(root);
        TreeNode *cur;
        while (!nodes.empty()) {
            vector<int> tmpRes;

            std::size_t n = nodes.size();

            while (n > 0) {
                if (flag) {
                    // 从前面取
                    cur = nodes.front();
                    nodes.pop_front();

                    if (cur->left)
                        nodes.push_back(cur->left);
                    if (cur->right)
                        nodes.push_back(cur->right);
                } else {
                    cur = nodes.back();
                    nodes.pop_back();
                    if (cur->right)
                        nodes.push_front(cur->right);

                    if (cur->left)
                        nodes.push_front(cur->left);
                }
                n--;
                tmpRes.push_back(cur->val);
            }
            flag = !flag;
            res.push_back(tmpRes);
        }
        return res;
    }

    vector<vector<int>> levelOrder2(TreeNode* root) {
        // 这里可以用两个栈来实现
        if (root == nullptr) return {};
        vector<vector<int>> res;
        int level(1);
        // 试试 decltype 的用法，以下和 queue<TreeNode*> 是一样的
        std::stack<std::pair<int, decltype(root)>> nodesStack1;
        std::stack<std::pair<int, decltype(root)>> nodesStack2;
        nodesStack1.push(std::make_pair(level, root));

        std::pair<int, TreeNode*> p;

        while (!nodesStack1.empty() || !nodesStack2.empty()) {
            while (!nodesStack1.empty()) {
                p = nodesStack1.top();
                nodesStack1.pop();
                if (res.size() < p.first) {
                    // TODO: 这个用法待学习，只是根据ide 提示修改的
                    // 这里等同于 res.push_back({});
                    res.emplace_back();
                }
                res[p.first -1].push_back(p.second->val);

                if (p.second->left) {
                    nodesStack2.push(std::make_pair(p.first + 1, p.second->left));
                }
                if (p.second->right) {
                    nodesStack2.push(std::make_pair(p.first + 1, p.second->right));
                }
            }
            while (!nodesStack2.empty()) {
                p = nodesStack2.top();
                nodesStack2.pop();
                if (res.size() < p.first) {
                    // TODO: 这个用法待学习，只是根据ide 提示修改的
                    // 这里等同于 res.push_back({});
                    res.emplace_back();
                }
                res[p.first -1].push_back(p.second->val);
                if (p.second->right) {
                    nodesStack1.push(std::make_pair(p.first + 1, p.second->right));
                }
                if (p.second->left) {
                    nodesStack1.push(std::make_pair(p.first + 1, p.second->left));
                }

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