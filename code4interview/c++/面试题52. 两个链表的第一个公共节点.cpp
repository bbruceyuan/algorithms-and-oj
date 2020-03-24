#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
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
    explicit ListNode (int x): val(x), next(nullptr) {};
};


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        auto cur = headA;
        while (cur) {
            lenA++;
            cur = cur->next;
        }

        cur = headB;
        while (cur) {
            lenB++;
            cur = cur->next;
        }

        int lenGap;
        if (lenA > lenB) {
            lenGap = lenA - lenB;
            while (lenGap) {
                headA = headA->next;
                lenGap--;
            }
        } else {
            lenGap = lenB - lenA;
            while (lenGap) {
                headB = headB->next;
                lenGap--;
 ;           }
        }

        while (true) {
            if (headA == headB) {
                break;
            } else {
                headA = headA->next;
                headB = headB->next;
            }
        }
        return headA;

    }
};


int main() {
    Solution solution;
    return 0;
}