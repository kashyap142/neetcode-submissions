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
   private:
    ListNode* reverse(ListNode* head) {
        ListNode *curr = head, *prev = nullptr;

        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;

            prev = curr, curr = next;
        }

        return prev;
    }

   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // reverse the list
        ListNode* rev = reverse(head);

        // delete nth node
        ListNode *node = rev, *prev = nullptr;
        int cnt = 1;
        while (cnt != n) {
            cnt++;
            prev = node;
            node = node->next;
        }

        if (n == 1) {
            rev = rev->next;
        } else {
            prev->next = node->next;
            delete(node);
        }

        // re-reverse the list
        ListNode* ans = reverse(rev);

        return ans;
    }
};
