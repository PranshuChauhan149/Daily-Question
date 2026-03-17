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
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
                temp = temp->next;
            } else {
                 temp->next = list2;
                list2 = list2->next;
                temp = temp->next;
            }
        }
        if(list1==NULL){
            temp->next = list2;
        }
        else{
            temp->next = list1;
        }
        
        return dummy->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0)
            return NULL;
        ListNode* ans = lists[0];
        for (int i = 1; i < n; i++) {
            ans = merge(ans, lists[i]);
        }
        return ans;
    }
};