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

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    explicit Node(int _val) {
        val = _val;
        left = nullptr;
        right = nullptr;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};


class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root) return root;

        Node *head = nullptr, *pre = nullptr;

        helper (root, head, pre);
        head->left = pre;
        pre->right = head;
        return head;
    }

    void helper (Node *root, Node *&head, Node *&pre) {
        if (!root) return;

        helper(root->left, head, pre);
        if (!head) {
            head = root;
            pre = root;
        } else {
            pre->right = root;
            root->left = pre;
            pre = root;
        }
        helper(root->right, head, pre);
    }
};


int main() {
    Solution solution;

    return 0;
}