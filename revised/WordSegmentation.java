/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Ideone
{

    /**
     * @param s: A string s
     * @param dict: A dictionary of words dict
     */
    public boolean wordSegmentation(String s, Set<String> dict) {
        // write your code here
        return dfs(s,dict, 0 ) ; 
    }
    public boolean dfs(String s , Set<String> dict, int start) {
        if(start == s.length() ) {
            return  true;  
        }
        for(int i  = start ; i< s.length() ; i++ ){
            String cur = s.substring(start , i + 1 ) ; 
            if(dict.contains(cur)) {
                dict.remove(cur) ; 
                if(dfs( s,  dict , i + 1 ) ) {
                    dict.add(cur) ;
                    return true; 
                }
                dict.add(cur) ; 
            }
        }
        return false ; 
    }


    public static void main (String[] args) throws java.lang.Exception
    {
        // your code goes here
        Ideone one = new Ideone() ; 
        Set<String>dict = new HashSet<String>() ; 
        dict.add("lint");
        dict.add("code");
        one.wordSegmentation("lintcode" , dict) ; 
    }
}
