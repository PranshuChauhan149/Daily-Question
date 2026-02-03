class Solution {
public:


    int ice(vector<int>&nums,int i){

       while(i<nums.size()-1 && nums[i]<nums[i+1]) i++;
       return i;
       
    }    
    int des(vector<int>&nums,int i){

       while(i<nums.size()-1 && nums[i]>nums[i+1]) i++;
       return i;
       
    }    


    bool isTrionic(vector<int>& nums) {

     int a = ice(nums,0);
     if(a==0) return false;
     int b = des(nums,a);
     if(a==b) return false;
     int c = ice(nums,b);
     if(b==c) return false;
     
     if(c==nums.size()-1) return true;
     return false;
    }
};