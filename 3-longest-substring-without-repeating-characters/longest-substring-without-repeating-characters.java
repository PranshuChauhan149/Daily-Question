class Solution {
    public int lengthOfLongestSubstring(String str) {
        HashMap<Character, Integer> mp = new HashMap<>();

        int i = 0;
        int n = str.length();
        int ans = 0;
        int j = 0;

        while (j < n) {
            char ch = str.charAt(j);

            if (mp.containsKey(ch)) {
                i = Math.max(i, mp.get(ch) + 1);
            }

            ans = Math.max(ans, j - i + 1);
            mp.put(ch, j);
            j++;
        }

        return ans;
    }
}