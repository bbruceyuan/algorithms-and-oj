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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        // 首先用 递归来判断
        if (!A && !B) return true;
        if (!A || !B) return false;
        // 否者说明两个节点都不是空
        bool res;
        if (A->val == B->val) {
            // 这里面的判断 1 2 是 1 2 3 的子结构，所一应该单独考虑考虑什么是中止条件
            res = haveSubStructure(A, B);
            return res;
        }
        res = isSubStructure(A->left, B) || isSubStructure(A->right, B);

        return res;
    }

    bool haveSubStructure (TreeNode *A, TreeNode *B) {
        if (!B) return true;
        if (!A) return false;
        if (A->val != B->val) return false;

        bool res = false;
        res = haveSubStructure(A->left, B->left) && haveSubStructure(A->right, B->right);
        return res;
    }
};

int main() {
    Solution solution;
    return 0;
}