/**
 * O(logm + logn)
 */
class Solution {
public:
    bool bst(vector<int> & nums,int target,int s,int e){
        int mid = (s+e)/2;
        while(s < e ) {
            mid = (s+e)/2;
            if(target < nums[mid] ) {
                e = mid;
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
        int size = matrix[0].size();
        int s =0  ,e = matrix.size() ; 
        while(s < e) {
            mid = (s+e)/2 ;
            if(target < matrix[mid][size-1] ){
                e = mid ;
                if(mid-1>=0&&target > matrix[mid-1][size-1] ){
                    s = mid;
                    break;
                }
            }else if(target > matrix[mid][size-1] ){
                s = mid+1;
                if(mid+1<matrix.size()&&target < matrix[mid+1][size-1] ){
                    break;
                }
            }else{
                return true;
            }
        }
        if( s >= matrix.size() ) return false;
        // i 
        return bst(matrix[s],target,0,size);

    }
};

