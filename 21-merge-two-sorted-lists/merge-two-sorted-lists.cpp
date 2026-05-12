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


    ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode* dummy = new ListNode(-1);
        ListNode* ans = dummy;
        ListNode* list1 = l1;
        ListNode* list2 = l2;
        while(list1 && list2){
            cout<<list1->val;
            if(list1->val <= list2->val){
                ans->next = list1;
                list1=list1->next;
                ans = ans->next;
            }else{
                ans->next = list2;
                list2=list2->next;
                ans = ans->next;
            }
        }
        if(list1==NULL){
            ans->next = list2;
        }
        else{
            ans->next = list1;
        }
        return dummy->next;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = merge(list1,list2);
        return ans;
    }
};