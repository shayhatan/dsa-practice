#include <bits/stdc++.h>
using namespace std;

/*
 * Reverse a singly linked list using iterative pointer manipulation.
 * Time: O(n), Space: O(1)
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};
