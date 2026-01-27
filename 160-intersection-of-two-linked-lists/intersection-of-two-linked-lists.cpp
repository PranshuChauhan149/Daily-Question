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
        int c1 = 0;
        ListNode* temp1 = headA;
        while (temp1) {
            c1++;
            temp1 = temp1->next;
        }
        int c2 = 0;
        ListNode* temp2 = headB;
        while (temp2) {
            c2++;
            temp2 = temp2->next;
        }
        int d = abs(c2 - c1);
        temp1 = headA;
        temp2 = headB;
        if (c1 > c2) {
            for (int i = 0; i < d; i++) {
                temp1 = temp1->next;
            }
        }
        if (c2 > c1) {
            for (int i = 0; i < d; i++) {
                temp2 = temp2->next;
            }
        }
        while (temp1 != NULL) {
            if (temp1 == temp2)
                return temp1;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return NULL;
    }
};