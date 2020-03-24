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
    ListNode *deleteNode (ListNode *head, int val) {
        auto dummy = new ListNode(0);
        dummy->next = head;
        auto pre = dummy;

        while (head) {
            if (head->val == val) {
                pre->next = head->next;
                break;
            } else {
                pre = head;
                head = head->next;
            }
        }
        return dummy->next;

    }

    ListNode* deleteNodeRecursive(ListNode* head, int val) {
        if (head->val == val)
            return head->next;
        head->next = deleteNodeRecursive(head->next, val);
        return head;
    }

};

int main () {

    return 0;
}