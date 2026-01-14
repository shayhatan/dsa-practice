#include <bits/stdc++.h>
using namespace std;

/*
 * Reorder list in-place: find middle (fast/slow), reverse second half, then weave.
 * Time: O(n), Space: O(1)
 */

class Solution {
    ListNode* getMiddle(ListNode* head) {
        ListNode* s = head;
        ListNode* f = head;

        while (f && f->next) {
            s = s->next;
            f = f->next->next;
        }

        return s;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* p = head;
        ListNode* prev = nullptr;

        while (p) {
            ListNode* next = p->next;
            p->next = prev;
            prev = p;
            p = next;
        }

        return prev;
    }

public:
    void reorderList(ListNode* head) {
        ListNode* firstH = head;
        ListNode* secondH = getMiddle(head);
        secondH = reverseList(secondH);

        while (secondH->next) {
            ListNode* nextFirst = firstH->next;
            ListNode* nextSecond = secondH->next;

            firstH->next = secondH;
            secondH->next = nextFirst;

            firstH = nextFirst;
            secondH = nextSecond;
        }
    }
};
