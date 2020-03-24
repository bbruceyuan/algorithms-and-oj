#include <iostream>
#include <string>
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
    explicit ListNode (int x): val(x), next(nullptr) {};
};


class Solution {
public:
    ListNode* reverseList(ListNode *head) {
        // 非递归
        ListNode* pre = nullptr, *cur = head;
        ListNode* nxt;

        while (cur) {
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }

    ListNode* reverseListRecursive(ListNode* head) {
        // 使用递归的方法来做
        if (head == nullptr || head->next == nullptr) return head;
        auto result = reverseListRecursive(head->next);
        head->next->next = head;
        head->next = nullptr;
        return result;
    }
};


int main () {

    return 0;
}