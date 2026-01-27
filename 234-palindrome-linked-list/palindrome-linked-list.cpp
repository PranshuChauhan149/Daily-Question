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

    ListNode* rev(ListNode* head){
        ListNode* forword = NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr!=NULL){
            forword = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forword;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
         if (fast != NULL) {
            slow = slow->next;
        }
       ListNode* pp = rev(slow);
       ListNode* temp = head;
       while(pp){
        if(temp->val!=pp->val){
            return false;
        }
            temp=temp->next;
            pp=pp->next;
       }
       return true;

    }
};