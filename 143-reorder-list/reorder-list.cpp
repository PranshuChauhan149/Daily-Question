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
    ListNode* rev(ListNode* root) {
        ListNode* curr = root;
        ListNode* forword = NULL;
        ListNode* prev = NULL;

        while (curr) {
            forword = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forword;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
     
        ListNode* t = slow->next;
        slow->next = NULL;
        ListNode* temp = rev(t);
        slow = head;
        ListNode* temp1;
        ListNode* temp2;

        while(temp){
            temp1 = slow->next;
            temp2 = temp->next;
            slow->next = temp;
            temp->next = temp1;

            slow = temp1;
            temp = temp2;
           

        }
        
    }
};