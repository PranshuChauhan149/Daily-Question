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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int>st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        while(head and st.count(head->val)){
          head=head->next;
        }
        if(!head) return nullptr;
        ListNode* temp = head;
        while(temp and temp->next){
            if(st.find(temp->next->val)!=st.end()){
                temp->next = temp->next->next;
            }
            else{
                temp= temp->next;
            }
        }
        return head;
    }
};