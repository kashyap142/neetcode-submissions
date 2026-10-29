/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        unordered_set<ListNode*> st1;

        while(headA != nullptr) {
            st1.insert(headA);
            headA = headA -> next;
        }

        while(headB != nullptr) {
            if(st1.find(headB) != nullptr) {
                return headB;
            }
            headB = headB -> next;
        }

        return nullptr;
    }
};