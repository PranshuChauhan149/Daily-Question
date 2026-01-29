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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* temp = head;
        int c = 0;
        while (temp) {
            c++;
            temp = temp->next;
        }

        k = k % c;
        ListNode* slow = head;
        temp = head;
        for (int i = 0; i < k ; i++) {
            temp = temp->next;
        }
        while (temp && temp->next != NULL) {
            temp = temp->next;
            slow = slow->next;
        }
        temp->next = head;
        head = slow->next;
        slow->next = NULL;
        return head;
    }
};