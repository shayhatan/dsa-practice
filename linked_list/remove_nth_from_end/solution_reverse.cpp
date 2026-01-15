#include <bits/stdc++.h>
using namespace std;

/*
 * Alternative solution:
 * Reverse list, remove Kth node from start, reverse back.
 * Time: O(n), Space: O(1)
 */

class Solution {
    ListNode* reverse(ListNode* node) {
        ListNode* prev = nullptr;
        while (node) {
            ListNode* next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }
        return prev;
    }

    ListNode* removeKth(ListNode* head, int k) {
        int cnt = 1;
        ListNode* node = head;
        ListNode* prev = nullptr;

        while (cnt++ < k) {
            prev = node;
            node = node->next;
        }

        if (node) {
            if (k == 1) {
                return head->next;
            }
            prev->next = node->next;
        }
        return head;
    }

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        head = reverse(head);
        head = removeKth(head, n);
        return reverse(head);
    }
};
