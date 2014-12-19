/**
 * O(logm + logn)
 * 1. Integers in each row are sorted from left to right.
 * 2. The first integer of each row is greater than the last integer of the previous row. 
 * prop 2 is important
 */
class Solution {
public:
    bool bst(vector<int> & nums,int target,int s,int e){
        int mid = (s+e)/2;
        while(s <= e ) {
            mid = (s+e)/2;
            if(target < nums[mid] ) {
                e = mid-1;
            }else if(target > nums[mid] ) {
                s = mid + 1 ;
            }else{
                return true;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(matrix.size() == 0 || matrix[0].size() == 0 ) return false; 
        int size = matrix[0].size();
        int s =0  ,e = matrix.size() -1 ;int mid = 0 ;  
        while(s <= e) {
            mid = (s+e)/2 ;
            if(target < matrix[mid][size-1] ){
                e = mid-1 ;
            }else if(target > matrix[mid][size-1] ){
                s = mid+1;
            }else{
                return true;
            }
        }
        if( s >= matrix.size() ) return false;
        // i 
        return bst(matrix[s],target,0,size-1);

    }
};


