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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *c1 = list1, *c2 = list2;

        // ListNode ans(0);
        ListNode *ans = new ListNode();
        ListNode* last = ans;

        while (c1 != nullptr && c2 != nullptr) {
            if (c1->val <= c2->val) {
                last->next = c1;
                last = c1;
                c1 = c1->next;
            } else {
                last->next = c2;
                last = c2;
                c2 = c2->next;
            }
        }

        if (c1 != nullptr) {
            last->next = c1;
        }
        if (c2 != nullptr) {
            last->next = c2;
        }

        return ans->next;
    }
};
