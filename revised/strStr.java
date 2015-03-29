/**
 1. basic algorithm
 2. KMP
 3. BM
 4. Sunday
 Reference: http://dsqiu.iteye.com/blog/1700312
 */
class Solution {
    /**
     * Returns a index to the first occurrence of target in source, or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    public int strStr_basic(String source, String target) {
        //write your code here

        if(source == null )  return  -1 ;
        if(target == null) return -1 ;
        if( target.length() == 0) {
            return 0 ;
        }
        //
        for(int i = 0 ; i <= source.length() - target.length() ; i++) {
            int j = 0 , t = i ;
            while(t<source.length() && j < target.length() && source.charAt(t) == target.charAt(j)) {
                t++ ;
                j++ ;
            }
            if(j==target.length()) {
                return i ;
            }
        }
        return -1;
    }
    // sunday algorithm is very clear ! better than KMP .
    public int strStr_sunday(String source, String target) {
        //write your code here

        if(source == null )  return  -1 ;
        if(target == null) return -1 ;
        if( target.length() == 0) {
            return 0 ;
        }
        int []hash = new int[256] ;
        for(int i = 0 ; i < target.length() ; i ++) {
            hash[target.charAt(i)] = i ;
        }
        int start = 0 , j = 0 ;
        while(true) {
            int i = start ;  j = 0 ;
            while( i < source.length() && j < target.length() && source.charAt(i) == target.charAt(j)) {
                i++ ; j++ ;
            }
            if(j == target.length() ) {
                return start ;
            }

            if(i == source.length() || start + target.length() >= source.length() ) {
                return -1 ;
            }

            // find next possible start!    
            char schar = source.charAt(start + target.length() ) ;
            // move
            start +=   target.length() - hash[schar] ;
        }

    }
    // KMP  key:  Pattern Array (Next Array)
    public int strStr(String source, String target) {
        //write your code here

        if(source == null )  return  -1 ;
        if(target == null) return -1 ;
        if( target.length() == 0) {
            return 0 ;
        }
        int []next = new int[target.length()] ;
        next[0] = -1 ;
        int i = 0  ,j = -1  ;
        while( i < target.length()-1) {
            if( j == -1 || target.charAt(i) == target.charAt(j)) {
                i++ ; j++ ;
                next[i] = j ;
            }else{
                j = next[j] ;
            }
        }

        i = 0 ; j = 0 ;
        while( i < source.length() && j< target.length() ){
            if( j== - 1 || source.charAt(i) == target.charAt(j)) {
                i++ ; j++ ;
            }else{
                j = next[j] ;
            }
        }

        if( j == target.length() ) {
            return i - target.length() ;
        }else{
            return -1;
        }
    }
    public static  void main(String []args) {
        int a = 'a' + 1 ;
        System.out.println(a );
        Solution  sol = new Solution();
        String source = "bcbcbd" ;
        String target = "bcbd";
        int pos = sol.strStr(source, target) ;
        System.out.println(pos);
    }

}
