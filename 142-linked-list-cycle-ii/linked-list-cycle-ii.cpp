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
    ListNode* detectCycle(ListNode* head) {
           if(head==NULL) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        int c = 0;
        while (fast && fast->next) {
           
            slow = slow->next;
            fast = fast->next->next;
             if (slow == fast) {
                c++;
                break;
            }
        }
        if (c == 0)
            return NULL;

        slow = head;
        while (true) {
            if (slow == fast)
                return slow;
            fast = fast->next;
            slow = slow->next;
        }
        return NULL;
    }
};