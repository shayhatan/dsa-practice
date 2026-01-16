#include <bits/stdc++.h>
using namespace std;

/*
 * Copy list with random pointer using hash map (old node -> new node).
 * Two passes: create nodes, then wire next/random.
 * Time: O(n), Space: O(n)
 */

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        unordered_map<Node*, Node*> copies;

        for (Node* curr = head; curr; curr = curr->next) {
            copies[curr] = new Node(curr->val);
        }

        for (Node* curr = head; curr; curr = curr->next) {
            copies[curr]->next = copies[curr->next];
            if (curr->random)
                copies[curr]->random = copies[curr->random];
        }

        return copies[head];
    }
};
