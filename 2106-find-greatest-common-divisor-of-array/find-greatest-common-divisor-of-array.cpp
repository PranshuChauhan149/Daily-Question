class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n = nums.size();
        int a = *min_element(nums.begin(),nums.end());
        int b = *max_element(nums.begin(),nums.end());
        
        while(b!=0){
            int r = a%b;
            if(r == 0) return b;
            a = b;
            b= r;
        }
        return 0;
    }
};