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

        ListNode *ans = nullptr, *last = nullptr;

        while (c1 != nullptr && c2 != nullptr) {
            if (c1->val <= c2->val) {
                if (ans == nullptr) {
                    ans = c1;
                } else {
                    last->next = c1;
                }
                last = c1;
                c1 = c1->next;
            } else {
                if (ans == nullptr) {
                    ans = c2;
                } else {
                    last->next = c2;
                }
                last = c2;
                c2 = c2->next;
            }
        }

        while (c1 != nullptr) {
            if (ans == nullptr) {
                ans = c1;
            } else {
                last->next = c1;
            }
            last = c1;
            c1 = c1->next;
        }

        while (c2 != nullptr) {
            if (ans == nullptr) {
                ans = c2;
            } else {
                last->next = c2;
            }
            last = c2;
            c2 = c2->next;
        }

        return ans;
    }
};
