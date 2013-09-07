/**
 * O(logn)  
 * 先找到最小的值;然后分成两段找
 */
class Solution {
public:
    int minsearch(int A[],int s,int e){
        int mid = (s+e)/2;
        if(mid == s ) {
            return s; 
        }
        if(A[s]<=A[mid]){
			if(s>=1 && A[s-1] > A[s] ) return s;
            return  minsearch(A,mid+1,e);
			
        }else {
            if(mid>=1 && A[mid-1] > A[mid]) return mid;
            return minsearch(A,s,mid);
        }
    }
    int bsearch(int A[],int s,int e,int target){
        if(s >= e ) return -1;
        int mid = (s+e)/2;
        if(target<A[mid]){
            return  bsearch(A,s,mid,target); 
        }else if(target > A[mid]){
            return  bsearch(A,mid+1,e,target);
        }else{
            return mid;
        }
    }
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( n == 0 ) return -1;
        int minpos = minsearch(A,0,n);
        int l = bsearch(A,0,minpos,target);
        if( l == -1 ) {
            l = bsearch(A,minpos,n,target);
        }
        return l;
    }
};

