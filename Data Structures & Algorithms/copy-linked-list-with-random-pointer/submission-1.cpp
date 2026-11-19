/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        mp.insert({nullptr, nullptr});

        for (Node *c = head; c != nullptr; c = c->next) {
            mp[c] = new Node(c->val);
        }

        for (Node* c = head; c != nullptr; c = c->next) {
            mp[c]->next = mp[c->next];
            mp[c]->random = mp[c->random];
        }

        return mp[head];
    }
};
