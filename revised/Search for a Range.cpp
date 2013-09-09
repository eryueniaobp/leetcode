/**
 * O(logn) 
 * 左边界 + 右边界 即可
 */
class Solution {
public:
    int bsearch(int A[],int n,int target,bool left){
        int l = 0;  
        int r = n-1;  
        while (l <= r) {  
            int mid = l+(r-l)/2;  
            if (A[mid] > target)
                r = mid-1;  
            else if (A[mid] < target)  
                l = mid+1;  
            else{
                left?(r= mid - 1):(l=mid+1);
            }
        }  
        return left?l:r;
    }
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret;
        int l = bsearch(A,n,target,true);
        int r = bsearch(A,n,target,false);
        if(A[l] != target || A[r] != target ) {
            l = r = -1;
        }
        ret.push_back(l);
        ret.push_back(r);
        return ret;
    }
};

