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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        // 典型使用双指针
        auto fast = head;
        while (fast && k) {
            fast = fast->next;
            k--;
        }

        while (fast) {
            fast = fast->next;
            head = head->next;
        }
        return head;
    }
    /*
     * 或者再两次遍历，或者用数组存储，然后直接定位
     * 倒是看到有人用递归，实际上不如 直接用数组 （这点需要注意）
     */
};

int main () {

    return 0;
}