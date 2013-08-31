class Solution {
    int tag[1000][1000];
    vector<vector<int> > _grid;
public:
    int dfs(int m,int n) {
        if(_grid[m-1][n-1] == 1 ){
            return 0;
        }
        if(m == 1 ) {
            for(int i = 0 ; i < n ;i ++ ){
                if(_grid[0][i] == 1 ){
                    return 0;
                }
                
            }
            return 1;
        }
        if(n == 1 ) {
            for(int i = 0 ; i < m ;i ++ ){
                if(_grid[i][0] == 1 ){
                    return 0;
                }
                
            }
            return 1;
        }
        
        if(tag[m][n] != 0 ) {
            return tag[m][n];
        }
        int sum = 0 ;
        for(int i = n ; i >=1 ; i -- ) {
            if(_grid[m-1][i-1] == 1){
                break;
            }
            sum += uniquePaths(m-1,i);
        }
        tag[m][n] = sum; 
        return sum;
    }
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       // fill(tag,tag+1000,-1);
        memset(tag,0,1000*1000*sizeof(int));
        _grid = obstacleGrid;
        return dfs(obstacleGrid.size(),obstacleGrid[0].size());
    }

};


