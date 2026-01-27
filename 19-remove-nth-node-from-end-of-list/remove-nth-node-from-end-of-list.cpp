
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) { 

        ListNode* fast = head;
        for(int i=0;i<n;i++){
            fast = fast->next;
        }
        if(fast==NULL) return head->next;
        ListNode* slow = head;
        while(fast && fast->next){
            fast=fast->next;
            slow=slow->next;
        }
        
        if( slow->next != NULL) slow->next = slow->next->next;
        return head;
    }
};