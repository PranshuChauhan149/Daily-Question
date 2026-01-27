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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* aa = dummy;
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        int carry = 0;
        while(t1 && t2){
            int d = carry +  t1->val + t2 ->val;
            int val = d%10;
            ListNode* a = new ListNode(val);
            aa->next = a;
            aa =aa->next;
            carry  = d/10;
            t1=t1->next;
            t2=t2->next;
        }
        if(t1==NULL){
            while(t2){
             int d = carry + t2 ->val;
            int val = d%10;
            ListNode* a = new ListNode(val);
            aa->next = a;
            aa =aa->next;
            carry  = d/10;
            t2=t2->next;
            }
        }
        if(t2==NULL){
            while(t1){
             int d = carry  +t1 ->val;
            int val = d%10;
            ListNode* a = new ListNode(val);
            aa->next = a;
            aa =aa->next;
            carry  = d/10;
            t1=t1->next;
            }
        }
        if(carry){
            ListNode* a = new ListNode(carry);
            aa->next = a;
            aa =aa->next;
        }
        return dummy->next;
    }
};