#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


struct ListNode {
    int val;
    ListNode *next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        stack<int> s;
        while(head) {
            s.push(head->val);
            head = head->next;
        }
        while (!s.empty()) {
            res.push_back(s.top());
            s.pop();
        }
        
        return res;
    }

    vector<int> reversePrint2(ListNode *head) {
        vector<int> res;
        reversePrintRecursive(head, res);
        return res;
    }

    void reversePrintRecursive(ListNode *head, vector<int> &res) {
        // 这是一个辅助函数
        if (head == nullptr) return;
        reversePrintRecursive(head->next, res);
        res.push_back(head->val);
    }
};

int main() {
    Solution solution;
    auto *head = new ListNode(0);
    auto cur = head;
    for (int i = 0; i < 5; i++) {
        cur->next = new ListNode(i);
        cur = cur->next;
    }
    cur->next = nullptr;
    vector<int> res = solution.reversePrint2(head->next);
    for (auto i: res) {
        cout << i << endl;
    }
    return 0;
}