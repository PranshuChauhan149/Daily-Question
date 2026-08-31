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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans;
        ListNode* slow = head;
        ListNode* fast = head->next;
        ListNode* prev = NULL;
        int count = 0;
        while (fast) {
            if (prev != NULL) {
                if (prev->val < slow->val && slow->val > fast->val) {
                    ans.push_back(count);
                } else if (prev->val > slow->val && slow->val < fast->val) {
                    ans.push_back(count);
                }
            }
            prev = slow;
            slow = slow->next;
            fast = fast->next;

            count++;
        }
        if (ans.size() < 2)
            return {-1, -1};
        int a = INT_MAX;
        for (int i = 0; i < ans.size() - 1; i++) {
            a = min(a, ans[i + 1] - ans[i]);
        }
        return {a,  ans[ans.size() - 1] - ans[0]};
    }
};