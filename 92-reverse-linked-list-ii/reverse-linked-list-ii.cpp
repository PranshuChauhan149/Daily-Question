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
    ListNode* reverse(ListNode* head) {
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

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right)
            return head;
        ListNode* slow = head;
        ListNode* fast = head;
          ListNode* prev = NULL;

        left--;
        right--;
        while (right) {
            if (left) {
                prev= slow;
                slow = slow->next;
                left--;
            }
            fast = fast->next;
            right--;
        }
        cout << slow->val;
        cout << fast->val;
        ListNode* dd = fast->next;
        fast->next = NULL;

        ListNode* r = slow;
        ListNode* ff = reverse(r);
        if(prev){
            prev->next = ff;
        }
        else{
            head = ff;
        }

        r->next = dd;
        return head;
    }
};