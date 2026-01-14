#include <bits/stdc++.h>
using namespace std;

/*
 * Detect cycle in a linked list using fast and slow pointers (Floyd's algorithm).
 * Time: O(n), Space: O(1)
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* f = head;
        ListNode* s = head;

        while (f && f->next) {
            s = s->next;
            f = f->next->next;
            if (f == s) return true;
        }
        return false;
    }
};
