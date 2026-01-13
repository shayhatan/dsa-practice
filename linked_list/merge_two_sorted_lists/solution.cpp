#include <bits/stdc++.h>
using namespace std;

/*
 * Merge two sorted linked lists using two pointers.
 * Initialize head once, then iteratively attach the smaller node.
 * Time: O(n + m), Space: O(1)
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        ListNode* merged;

        if (l1->val < l2->val) {
            merged = l1;
            l1 = l1->next;
        } else {
            merged = l2;
            l2 = l2->next;
        }

        ListNode* curr = merged;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }

        curr->next = l1 ? l1 : l2;
        return merged;
    }
};
