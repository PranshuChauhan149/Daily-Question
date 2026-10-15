class Solution {
    public int singleNumber(int[] nums) {
        int n = nums.length;
        HashMap<Integer,Integer>mp = new HashMap<>();
        for(int i =0;i<n;i++){
            mp.put(nums[i],mp.getOrDefault(nums[i],0)+1);
        }
        for(int ele : mp.keySet()){
            if(mp.get(ele) == 1) return ele;
        }
        return -1;
    }
}