/*
 * O(n) 
 * 每次都使得一个元素归位 
 * 这个写法更加清晰
 */
class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0 ; 
        int j = 0 , k = 0 ; 
        while(i<n){
            if(A[i]  ==2 ) {
            }else if(A[i] == 1 ) {
                swap(A[i],A[k]);
                k++ ; 
            }else{
                A[i] = A[k];
                A[k] = A[j] ; 
                A[j] = 0 ;
                j++;
                k++;
            }
            i++;
        }
    }
};

