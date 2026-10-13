class Solution {
    public boolean isAnagram(String s, String t) {
        char []a = s.toCharArray();
        Arrays.sort(a);
        char []b = t.toCharArray();
        Arrays.sort(b);
        s = new String(a);
        t = new String(b);
        if(s.equals(t)) return true;
        return false;

     
    }
}