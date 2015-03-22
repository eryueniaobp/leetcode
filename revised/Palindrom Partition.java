// Given a string s, partition s such that every substring of the partition is a palindrome.  
// lintcode and leetcode
// palin[i][j] O(N^2) dynamic programming
import java.util.*  ;
public class Solution {
    /**
     * @param s: A string
     * @return: A list of lists of string
     */
    List<List<String>> ret = null;
    int []pos = null;
    boolean [][]palin = null; 
    public List<List<String>> partition(String ss) {
        ret = new ArrayList<List<String>> () ;
        char []s = ss.toCharArray(); 
        int len =  s.length  ;
        palin = new boolean[len][len] ;
        for(int i = 0 ;  i < len ; i ++ ) {
            for(int j =  0 ; j< len ; j++ ) {
                palin[i][j]  = false;
                if(i == j )  palin[i][j] = true  ;
            }
        }
        for(int i = len - 1 ; i>= 0 ; i -- ) {
            for(int j = i  ;  j < len ; j ++ ) {
                if(s[i] == s[j] && ( j-i<2 || palin[i+1][j-1] )) {
                    palin[i][j] = true ;
                }
            }
        }
        pos = new int[s.length] ; Arrays.fill(pos , 0 ) ;
        dfs(s ,  0 ) ;
        return ret ;


    }
    protected void dfs(char []s  , int start ) {
        if(start == s.length ) {
            List<String> row = new ArrayList<String>() ;
            StringBuilder sb = null ;
            for(int i = 0 ; i< s.length ; i++ ){
                if(pos[i] == 1 ) {
                    if(sb!=null ) {
                        row.add(sb.toString())  ;
                    }
                    sb = new StringBuilder() ;
                    sb.append(s[i]) ;
                }else{
                    sb.append(s[i]) ;
                }
            }
            if(sb!=null)  row.add(sb.toString()) ;
            ret.add(row);
            return ;
        }
        pos[start ] = 1 ;
        for(int i = start ; i < s.length ; i++ ) {
            if(palin[start][i] ) {
                dfs( s , i + 1 ) ;
            }
        }
        pos[start] = 0  ;
    }
}


