/*
 * O(n) 
 * 每次都使得一个元素归位
 */
class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0 ; 
        int j = n -1 , k = n-1;
        while(i<=j){
            if(A[i]  ==2 ) {
                swap(A[i],A[k]);
                k--;
                if( k < j ) {
                    j = k ;
                }
            }else if(A[i] == 1 ) {
                swap(A[i],A[j]);
                j-- ; 
            }else{
                i++;
            }
        }
    }
};

