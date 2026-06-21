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
        ListNode* l1 = list1;
        ListNode* l2 = list2;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                
                temp->next = l1;
                temp = temp->next;
                l1 = l1->next;
            } else {
              
                temp->next = l2;
                temp = temp->next;
                l2 = l2->next;
            }
        }
        if (l1) {
            temp->next = l1;
        }
        else{
            temp->next = l2;
        }
        return dummy->next;
    }

    ListNode* middle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* mergeSort(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* left = middle(head);
        ListNode* right = left->next;
        left->next = NULL;
        ListNode* list1 = mergeSort(head);
        ListNode* list2 = mergeSort(right);
       return  merge(list1, list2);
    }

    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
        
    }
};