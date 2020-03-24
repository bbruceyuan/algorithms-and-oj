#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <iostream>
#include <sstream>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};


class Node {
public:
    int val;
    Node* next;
    Node* random;

    explicit Node (int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        std::unordered_map<Node *, Node*> mp;
        auto root = head, cur = head;
        while (cur) {
            mp[cur] = new Node(cur->val);
            cur = cur->next;
        }
        cur = head;
        // 从新遍历一遍
        while (cur) {
            if (cur->next)
                mp[cur]->next = mp[cur->next];
            if (cur->random)
                mp[cur]->random = mp[cur->random];
            cur = cur->next;
        }
        return mp[head];

    }
};


int main() {
//    string s = "[1,2,3,null,null,4,5]";
    string s = "[5,2,3,null,null,2,4,3,1]";



//    string str = "hello world";
//    cout << s.find_last_not_of("world");

    return 0;
}