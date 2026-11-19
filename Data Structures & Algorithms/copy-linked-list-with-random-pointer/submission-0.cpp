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
        Node dummy(0);

        unordered_map<Node*, Node*> mp;

        Node *curr = head, *node = &dummy;

        while (curr != nullptr) {
            node->next = new Node(curr->val);

            mp[curr] = node->next;
            curr = curr->next;
            node = node->next;
        }

        curr = head, node = dummy.next;

        while (curr != nullptr) {
            if (curr->random != nullptr) {
                node->random = mp[curr->random];
            }
            curr = curr->next;
            node = node->next;
        }

        return dummy.next;
    }
};
