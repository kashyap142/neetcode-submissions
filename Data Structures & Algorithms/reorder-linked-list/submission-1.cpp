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
        if (head == nullptr or head->next == nullptr) {
            return;
        }

        // find mid
        ListNode *slow = head, *fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* mid = slow->next;
        slow->next = nullptr;

        // reverse the list
        ListNode *curr = mid, *prev = nullptr;
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }

        // start merging
        ListNode *first = head, *second = prev;

        while (first != nullptr && second != nullptr) {
            ListNode *n1 = first->next, *n2 = second->next;

            first->next = second;
            second->next = n1;

            first = n1, second = n2;
        }
    }
};

/*
    1. split the list in half (A / B) [find mid]
    2. B' = Reverse the second half (B) [reverse the list]
    3. Traverse both A and B'
*/