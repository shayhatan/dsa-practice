#include <bits/stdc++.h>
using namespace std;

/*
 * Remove Nth node from end using fast & slow pointers with a dummy node.
 * One pass.
 * Time: O(n), Space: O(1)
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

        for (int i = 0; i <= n; ++i) {
            fast = fast->next;
        }

        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;
        return dummy.next;
    }
};
