/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
   public:
    void reorderList(ListNode* head) {
        deque<ListNode*> dq;

        ListNode* temp = head;
        while (temp != nullptr) {
            dq.push_back(temp);
            temp = temp->next;
        }

        ListNode dummy(0);
        ListNode* end = &dummy;

        while (!dq.empty()) {
            end->next = dq.front();
            end = end->next;
            dq.pop_front();

            if (!dq.empty()) {
                end->next = dq.back();
                end = end->next;
                dq.pop_back();
            }
        }
        end->next = nullptr; // break the loop
        head = dummy.next;
    }
};
