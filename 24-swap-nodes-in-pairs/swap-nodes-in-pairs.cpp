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
    ListNode* swapPairs(ListNode* head) {
        ListNode* even = new ListNode(-1);
        ListNode* e = even;
        ListNode* odd = new ListNode(-1);
        ListNode* o = odd;
        ListNode* temp = head;
        int c = 0;
        while(temp){
            if(c%2==0){
                ListNode* d = new ListNode(temp->val);
                e->next = d;
                e = e->next;
            }
            else{
                  ListNode* d = new ListNode(temp->val);
                o->next = d;
                o = o->next;
            }
            temp=temp->next;
            c++;
        }
    ListNode* t1 = even->next;
    ListNode* t2 = odd->next;
 
    ListNode* ans = head;
    int count =1;
        while(t1 && t2){
            if(count%2!=0){
                ans->val = t2->val;
                t2=t2->next;
                ans=ans->next;
            }
            else{
                ans->val = t1->val;
                t1=t1->next;
                ans=ans->next;
            }
            count++;
        }
        while(t1!=NULL){
             ans->val = t1->val;
                t1=t1->next;
                ans=ans->next;
        }
        while(t2!=NULL){
             ans->val = t2->val;
                t2=t2->next;
                ans=ans->next;
        }

        return head;

    }
};