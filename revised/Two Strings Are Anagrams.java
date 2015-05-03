public class Solution {
    /**
     * @param s: The first string
     * @param b: The second string
     * @return true or false
     */
    public boolean anagram(String s, String t) {
        if(s == null && t == null) return true ;
        if(s== null) return false ;
        if(t == null) return false ; 
        if(s.length() != t.length() ) return false ; 
        
        // write your code here
        char []sarr  = s.toCharArray() ;
        char []tarr = t.toCharArray() ; 
        Arrays.sort(sarr) ; 
        Arrays.sort(tarr)  ; 
        for(int i = 0 ; i < sarr.length ; i++) {
            if(sarr[i] != tarr[i]) {
                return false; 
            }
        }
        return true; 
    }
};
