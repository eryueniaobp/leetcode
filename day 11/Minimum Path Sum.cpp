class Solution {
    int tag[1000][1000];
public:
    int dfs(vector<vector<int> > &grid,int m,int n){
        if(m == 1 ){
            int sum = 0 ;
            for(int i = 0 ; i< n ;i ++ ) {
                sum += grid[0][i];
            }
            return sum;
        }
        if( n == 1 ) {
            int sum = 0 ;
            for(int i = 0 ;i < m ;i++){
                sum += grid[i][0];
            }
            return sum;
        }
        if(tag[m][n] != 0 ){
            return tag[m][n];
        }
        int curmin = INT_MAX;
        int sum = 0 ; 
        for(int i = n ; i>= 1 ; i -- ){
            int cursum = dfs(grid,m-1,i) ;
            sum += grid[m-1][i-1];
            cursum += sum;

            if(cursum < curmin){
                curmin= cursum;
            }
        }
        tag[m][n] = curmin;
        return curmin;
    }
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        memset(tag,0,1000*1000*sizeof(int));
        if(grid.size() == 0 || grid[0].size() == 0 ) return 0 ;
        return dfs(grid,grid.size(),grid[0].size());
    }
};



