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
    ListNode* findMid(ListNode* head) {
        ListNode *slow = head, *fast = head;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

    ListNode* reverse(ListNode* head) {
        ListNode *curr = head, *prev = nullptr;

        while (curr) {
            ListNode* tmp = curr->next;
            curr->next = prev;

            prev = curr, curr = tmp;
        }

        return prev;
    }

   public:
    void reorderList(ListNode* head) {
        ListNode* mid = findMid(head);
        ListNode *list2 = reverse(mid), *list1 = head;

        while (list1 != nullptr && list2 != nullptr) {
            ListNode *n1 = list1->next, *n2 = list2->next;

            list1->next = list2;
            list2->next = n1;

            list1 = n1, list2 = n2;
        }

        if (list1) {
            list1->next = nullptr;
        }
    }
};

/*
    1. split the list in half (A / B) [find mid]
    2. B' = Reverse the second half (B) [reverse the list]
    3. Traverse both A and B'
*/