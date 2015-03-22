// O(n) . while(true) block is important .
/**
Given a string source and a string target, find the minimum window in source which will contain all the characters in target.

Note
If there is no such window in source that covers all characters in target, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in source.

Example
source = "ADOBECODEBANC" target = "ABC" Minimum window is "BANC".

Challenge
Can you do it in time complexity O(n) ?

Clarification
Should the characters in minimum window has the same order in target?

    - Not necessary.
*/
import java.util.HashMap;
import java.util.Map;

public class Solution {
    /**
     * @param source: A string
     * @param target: A string
     * @return: A string denote the minimum window
     *          Return "" if there is no such a string
     */
    Map<Character,Integer> ch2cnt = null;
    public String minWindow(String source, String target) {

        char []sarr = source.toCharArray() ;
        char []tarr = target.toCharArray() ;
        ch2cnt = new HashMap<Character,Integer>() ;

        for(int i = 0 ; i<tarr.length ;i ++) {
           plus(tarr[i] , 1);
        }
        int cnt  = tarr.length ;
        int start = 0 ;
        int min = Integer.MAX_VALUE ;
        String window = "";

        for(int i = 0 ; i< sarr.length ; i ++){
            if( cnt ==  tarr.length) start = i  ;
            if(!ch2cnt.containsKey(sarr[i]) ) continue  ;

            if(left(sarr[i]) >  0 ) {
                cnt -- ;
            }
            // if left(sarr[i]) <= 0 , it will get a negative value .
            subtract(sarr[i] , 1)  ;

            if (cnt == 0 && (left(sarr[i]) == 0 || sarr[i] == sarr[start])) {
                // Only in this condition ,it may change the window size .
                // for example 
                // find ABC in  ABACA 
                while (true) { // the while was meant to find the next proper start!
                    if (ch2cnt.containsKey(sarr[start])) {
                        if (left(sarr[start]) != 0) { // Precisely speaking , it should be < 0   impossible to be >0 
                            plus(sarr[start], 1);
                        } else {
                            break; // must be == 0 
                        }

                    }
                    start++;
                }
                if (i - start + 1 < min) {
                    min = i - start + 1;
                    window = source.substring(start, i + 1);
                }

            }
        }

//        while()
        return window  ;
    }
    protected int left(char a ) {
        if(ch2cnt.containsKey(a)) {
            return ch2cnt.get(a) ;
        }
        throw new RuntimeException("KeyNotFound") ;
    }
    protected void plus(char s , int num  ) {
        if(ch2cnt.containsKey(s)) {
            int old = ch2cnt.get(s) ;
            ch2cnt.put(s  , old + num) ;
        }else {
            ch2cnt.put(s, num);
        }
    }
    protected void subtract(char s , int num  ) {
        if(ch2cnt.containsKey(s)) {
            int old = ch2cnt.get(s) ;
            ch2cnt.put(s  , old - num) ;
        }else {
            throw  new RuntimeException("KeyNotFound") ;
        }
    }
    public static void main(String []args){
        Solution sol = new Solution();
        System.out.println(sol.minWindow("ADOBECBA", "ABC"));
    }
}

