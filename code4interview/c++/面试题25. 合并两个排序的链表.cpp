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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        auto dummy = new ListNode(0);
        auto cur = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (l1) {
            cur->next = l1;
        }
        if (l2) {
            cur->next = l2;
        }
        return dummy->next;
    }

    ListNode *mergeTwoListRecursive(ListNode *l1, ListNode *l2) {
        if (l2 == nullptr && l1 == nullptr) return nullptr;
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;

        auto dummy = new ListNode(0);
        if (l1->val < l2->val) {
            dummy->next = l1;
            dummy->next->next = mergeTwoListRecursive(l1->next, l2);
        } else {
            dummy->next = l2;
            dummy->next->next = mergeTwoListRecursive(l1, l2->next);
        }

        return dummy->next;
    }
};


int main () {

    return 0;
}