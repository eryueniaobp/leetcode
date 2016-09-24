/**
 * O(logn)  
 * 先找到最小的值;然后分成两段找
 */
class Solution {
public:
    int minsearch(int A[],int n ){
        int i  = 0 , j = n -1 ; 
        while( i < j ) {
            int mid = (i+j)/2 ; 
            // just use A[mid] and A[j] ,we can decide which side the min-value is located on
            if(A[mid] < A[j]){
                j = mid ; 
            }else if(A[mid] > A[j]) {
                i = mid + 1; 
            }
        }
        return i  ; 
    }
    int bsearch(int A[],int s,int e,int target){
        int i = s , j = e-1 ;
        while(i<=j){
            int mid = (i+j)/2; 
            if(A[mid] < target ) {
                i = mid +1 ;
            }else if(A[mid] > target){
                j = mid - 1; 
            }else{
                return mid; 
            }
        }
        return -1 ;
    }
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( n == 0 ) return -1;
        int minpos = minsearch(A,n);
        
        int ret = -1 ;
        if(target > A[n-1]) {
            ret=   bsearch(A,0,minpos,target);
        }else{
            ret =  bsearch(A,minpos,n,target);
        }
        
        return ret ;
    }
};

//  just one binary search . ugly code ~ @deprecated 
//  improvement:  * use vals[0] and vals[N-1] to decide which side the target is in. *
//  after we have decided the target's side, there are 4 cases:  
// 4 cases: 
//  target < mid && mid in left side:   
//        if target in left side: j = mid - 1 ; 
//        if target in right side: i = mid + 1 ; 
//  target < mid && mid in right side:  target must be in  right side.  
//        j = mid-1;  
//  target > mid && mid in left side:   target must be in left side .  
//        i = mid+1 ; 
//  target > mid && mid in right side:  
//        if target in left side: j = mid -1 ; 
//        if target in right side: i = mid +1  ; 
class Solution {
    /** 
     * param A : an integer ratated sorted array
     * param target :  an integer to be searched
     * return : an integer
     */
public:
    bool normal(vector<int> &A , int mid , int i , int j ) {
        return A[mid]<=A[j] && A[mid]>=A[i]  ; 
    }
    bool right(vector<int> &A , int mid , int i , int j ) {
        return A[mid] >=A[j] && A[mid]>=A[i] ; 
    }
    bool left(vector<int> &A , int mid , int i , int j ) {
        return A[mid] <=A[j] && A[mid]<=A[i]  ;
    }
    int search(vector<int> &A, int target) {
        // write your code here
        if(A.size() == 0) return -1;
        int i = 0 , j = A.size() -1 ; 
        while( i <= j ) {
            int mid = i + (j-i) /2 ; 
            
            if(A[mid] == target) return mid ; 
            if( normal(A, mid , i , j)) {
                if(target < A[mid]) { // ############ 
                    j = mid -1 ;
                }else if(target > A[mid]) { 
                    i = mid + 1; 
                }
            }else if(right(A,mid,i,j)) {
                if(target < A[mid]) { // ##############
                    if(target <=A[j] ) {
                        i = mid + 1 ;
                    }else {
                        j = mid - 1; 
                    }
                }else{
                    i = mid + 1; 
                }
            }else {
                //left 
                if(target < A[mid] ) {  //#############
                    j = mid - 1; 
                }else {
                    if(target > A[j] ) {
                        j = mid - 1  ; 
                    }else{
                        i = mid + 1; 
                    }
                }
            }
            
        }
        return -1 ;
    }
};

