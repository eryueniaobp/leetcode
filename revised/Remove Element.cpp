/**
 * O(n) 
 */
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int start = 0;
        for(int i = 0; i < n; i++)
            if (elem != A[i])
            {
                A[start++] = A[i];
            }
            
        return start;
    }
};

// another solution  not clear as the above one 
public class Solution {
    /** 
     *@param A: A list of integers
     *@param elem: An integer
     *@return: The new length after remove
     */
    public int removeElement(int[] A, int elem) {
        // write your code here
        if(A.length == 0 ) return 0 ; 
        int i = 0 , j = A.length - 1 ;
        
        while(i <= j ) {
            while(i<=j && A[i] == elem) {
                int tmp = A[i] ; 
                A[i] = A[j] ; 
                A[j] = tmp  ;  
                j-- ; 
            }
            if( i <=j ) i++ ; 
        }
        return i; 
    }
}



