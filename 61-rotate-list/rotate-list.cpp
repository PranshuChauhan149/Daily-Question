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
        ListNode* temp = head;
        int n = 0;
        while (temp) {
            n++;
            temp = temp->next;
        }
        if(k == 0 || n==0) return head;
        k = k % n;
        if (k == 0)
            return head;
        temp = head;
        for (int i = 0; i < k; i++) {
            temp = temp->next;
        }
        ListNode* slow = head;
        while (temp && temp->next) {
            slow = slow->next;
            temp = temp->next;
        }
        temp->next = head;
        head = slow->next;
        slow->next = NULL;

        return head;
    }
};