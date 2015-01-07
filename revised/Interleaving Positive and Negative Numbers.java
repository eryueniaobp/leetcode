/*
Given an array with positive and negative integers. Re-range it to interleaving with positive and negative integers. 


Given [-1, -2, -3, 4, 5, 6], after re-range, it will be [-1, 5, -2, 4, -3, 6] or any other legal answer.

http://lintcode.com/zh-cn/problem/interleaving-positive-and-negative-numbers
*/
class Solution {
    /**
     * @param A: An integer array.
     * @return an integer array
     */
    public int[] rerange(int[] A) {
        int pcnt  = 0 , ncnt =0 ;
        for(int i =  0  ; i< A.length ; i ++ ){
            if(A[i]>0) pcnt ++ ;
            else{
                ncnt ++ ; 
            }
        }
        int prev = 0 ;
        if(pcnt > ncnt){
            prev = -1  ;
        }else{
            prev = 1 ; 
        }
        int i = 0;  
        while( i < A.length ){
            if(i>0) {
                prev = A[i-1] ; 
            }
            if(prev*A[i] >   0 ){
                int j = i ;     
                while(j < A.length && A[j]*prev > 0 ) j ++ ; 
                if( j < A.length){
                    int t = A[i] ; 
                    A[i] = A[j] ; 
                    A[j] =  t;  
                }
            }
            i++ ; 
        }
        return A; 
       
       
   }
}

