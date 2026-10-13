class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer,Integer> mp = new HashMap<>();
       
        int[] ans = new int[2];

        int n = nums.length;
        for(int i = 0;i<n;i++){
            int d = target - nums[i];
            if(mp.containsKey(d)){
               ans[0] = mp.get(d);
               ans[1] = i;
               return ans;
            }else{
                mp.put(nums[i],i);
            }
        }

return ans;

    }
}
