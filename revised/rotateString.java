public class Solution {
    /*
     * param A: A string
     * param offset: Rotate string with offset.
     * return: Rotated string.
     */
    public char[] rotateString(char[] A, int offset) {
        // wirte your code here
        if(A.length == 0 ) return A; 
        offset = offset%A.length ; 
        while(offset > 0 ) {
            char t = A[A.length-1]  ; 
            int i = A.length - 1 ; 
            while(i>0) {
                A[i] = A[i-1]  ;
                i -- ;
            }
            A[0] = t ; 
            offset -- ; 
        }
        return A ; 
    }
};

