/**
 * DP
 * f(i,j) = min(f(i-1,j),f(i,j-1)) + a(i,j) 
 */
class Solution {
private:
    int f[1000][1000];
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;
            
        f[0][0] = grid[0][0];
        
        for(int i = 1; i < grid.size(); i++)
            f[i][0] = f[i-1][0] + grid[i][0];
            
        for(int i = 1; i < grid[0].size(); i++)
            f[0][i] = f[0][i-1] + grid[0][i];
            
        for(int i = 1; i < grid.size(); i++)
            for(int j = 1; j < grid[0].size(); j++)
                f[i][j] = min(f[i-1][j], f[i][j-1]) + grid[i][j];
                
        return f[grid.size()-1][grid[0].size()-1];
    }
};
// Java Solution 
public class Solution {
    /**
     * @param grid: a list of lists of integers.
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    public int minPathSum(int[][] grid) {
        // write your code here
        if(grid.length == 0 ) return 0 ; 
        int [][]path = new int[grid.length][grid[0].length] ; 
        for(int i = 0 ; i < grid.length ; i++ ){
            path[i][0] = (i-1>=0?path[i-1][0] : 0)  + grid[i][0]   ;
        }
        for(int i = 0 ;i < grid[0].length ; i++){
            path[0][i] =  (i-1>=0?path[0][i-1] :0) + grid[0][i] ; 
        }
        for(int i = 1 ; i< grid.length ; i ++ ) {
            for(int j = 1 ;j <grid[0].length ; j++ ){
                path[i][j] = Math.min(path[i-1][j] , path[i][j-1] ) + grid[i][j] ; 
            }
        }
        return path[grid.length-1][grid[0].length-1];
    }
}
