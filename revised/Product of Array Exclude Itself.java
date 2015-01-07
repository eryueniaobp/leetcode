/**
Given an integers array A.

Define B[i] = A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1], calculate B without divide operation.

http://lintcode.com/zh-cn/problem/product-of-array-exclude-itself/
*/
public class Solution {
    /**
     * @param A: Given an integers array A
     * @return: A Long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    public ArrayList<Long> productExcludeItself(ArrayList<Integer> A) {
        if(A.size() <= 1 ) {
            return new ArrayList<Long>(); 
        }
        long []left = new long[A.size()] ;
        long []right = new long[A.size()];
        
        for(int i = 0 ; i < A.size() ; i++ ){
            if( i == 0 ) {
                left[i]  = (long)1  ; 
            }else{
                long prev = left[i-1] ; 
                left[i] = (prev * A.get(i-1)) ; 
            }
        }
        
        for(int i = A.size() -1 ; i >=0  ; i-- ){
            if( i == A.size()-1  ) {
                right[i] = ((long)1)  ; 
            }else{
                long prev = right[i+1] ; 
                right[i] = (prev * A.get(i+1)) ; 
            }
        }
        
        ArrayList<Long> pod = new ArrayList<Long>(); 
        for(int i =  0 ; i<A.size() ; i ++ ) {
            pod.add(left[i] * right[i]) ;
            
        }
        return pod ; 
        
        
    }
}


