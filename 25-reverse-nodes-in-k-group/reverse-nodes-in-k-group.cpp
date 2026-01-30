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


    ListNode* kthNode(ListNode* head,int k){
        k-=1;
        while(head && k--){
            head = head->next;
        }
        return head;
    }

   ListNode* reverseList(ListNode* head) {
         ListNode* curr = head;
        ListNode* forword = NULL;
        ListNode* prev = NULL;
        while(curr!=NULL){
            forword = curr->next;
            curr->next=prev;
            prev= curr;
            curr=forword;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = NULL;

        while(temp!=NULL){
            ListNode* kth = kthNode(temp,k);
            if(kth==NULL){
                if(prevNode) prevNode->next = temp;
                break;
            }

            ListNode* t = kth->next;
            kth->next = NULL;

         reverseList(temp);

             
            if(temp==head){
                head = kth;
            }
            else{
                prevNode->next = kth;
            }

            prevNode = temp;
            temp = t;

        }
    return head;
    }
};