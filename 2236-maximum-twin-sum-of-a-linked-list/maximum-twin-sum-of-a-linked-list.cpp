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
    ListNode* rev(ListNode* head) {
        ListNode* forword = NULL;
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr) {
            forword = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forword;
        }
        return prev;
    }

    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* start = slow->next;
        slow->next = NULL;
        ListNode* tm = rev(head);
        int ans = 0;
        while (tm) {
            int a = tm->val;
            int b = start->val;
            ans = max(ans, a + b);
            tm = tm->next;
            start = start->next;
        }
        return ans;
    }
};