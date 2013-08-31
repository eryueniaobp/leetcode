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
        int i = 0 ;
        for(i = 0  ; i< matrix.size() ; i++ ) {
            if( target <= matrix[i][size-1] ){
                break;
            }
        }
        if( i >= matrix.size() ) return false;
        // i 
        return bst(matrix[i],target,0,size);

    }
};

