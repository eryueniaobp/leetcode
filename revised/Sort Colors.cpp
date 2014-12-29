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
void sortKColors(vector<int> &colors,int k){
    int size = colors.size() ; 
    if(size <= 1 ) return ; 
    if(k == 1 ) return  ; 
    for(int i = k ; i> 0 ; i --){
        int st = 0 , end = size - 1 ; 
        while(st <= end){
            while(st<=end && colors[end] == i ) end -- ; 
            if(st > end) break;
            while(st<=end && colors[st] != i ) st ++  ; 
            if(st>end) break ; 
            colors[st] = colors[end] ; 
            colors[end] = i ; 
            st++ ; 
            end -- ; 
        }
        size = st ; 
    }
}
