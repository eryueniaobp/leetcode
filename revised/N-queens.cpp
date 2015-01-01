/**
 * DFS 即可
 */
class Solution {
private:
    vector<vector<string> > ret;
    int a[100];
    bool canUse[100];
public:
    bool check(int y, int n)
    {
        for(int i = 0; i < n; i++)
            if (abs(i - n) == abs(y - a[i]))
                return false;
        return true;
    }
    
    void solve(int dep, int maxDep)
    {
        if (dep == maxDep)
        {
            vector<string> ans;
            for(int i = 0; i < maxDep; i++)
            {
                string s;
                for(int j = 0; j < a[i]; j++)
                    s += '.';
                s += 'Q';
                for(int j = 0; j < maxDep - (a[i] + 1); j++)
                    s += '.';
                ans.push_back(s);
            }
            ret.push_back(ans);
            
            return;
        }
        
        for(int i = 0; i < maxDep; i++)
            if (canUse[i] && check(i, dep))
            {
                canUse[i] = false;
                a[dep] = i;
                solve(dep + 1, maxDep);
                canUse[i] = true;             
            }
    }
    
    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        memset(canUse, true, sizeof(canUse));
        solve(0, n);
        return ret;
    }
};
/**
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

 * 
*/ 
class Solution {
    /**
     * Get all distinct N-Queen solutions
     * @param n: The number of queens
     * @return: All distinct solutions
     * For example, A string '...Q' shows a queen on forth position
     */
    ArrayList<ArrayList<String>> rets = null ; 
    ArrayList<ArrayList<String>> solveNQueens(int n) {
        // write your code here
        rets = new ArrayList<ArrayList<String>>() ; 
        int [][]board = new int[n][n] ; 
        for(int i = 0 ;i < n ; i++){
            for(int j = 0 ; j< n ; j++){
                board[i][j] = 0 ; 
            }
        }
        dfs(board , n ) ; 
        return rets; 
    }
    boolean checkRow(int [][]board  , int r, int c ) {
        for(int i  = 0 ; i < board.length ; i++ ){
            if(i!=c && board[r][i] == 1 ) {
                return true ; 
            }
        }
        return false; 
    }
    boolean checkCol(int [][]board  , int r, int c ) {
        for(int i  = 0 ; i < board.length ; i++ ){
            if(i!=r && board[i][c] == 1 ) {
                return true ;  // conflict.
            }
        }
        return false; 
    }
    boolean checkDiagonal(int [][]board  , int r, int c ) {
        int i =  r +1 , j = c+1  ;
        int N = board.length ; 
        while(i < N && j < N) {
            if(board[i][j] == 1 ) return true; 
            i++ ;  j++ ; 
        }
        i = r-1  ;  j = c -1 ; 
        while(i>=0 && j>=0) {
            if(board[i][j] == 1 ) return true; 
            i -- ; j--;
        }
        i = r + 1 ; j = c-1 ; 
        while( i< N&& j>=0 ) {
            if(board[i][j] == 1 ) return true; 
            i ++ ; j--;
        }
        i = r-1 ; j = c+1 ; 
        while( i>=0 && j < N  ) {
            if(board[i][j] == 1 ) return true; 
            i -- ; j ++ ;
        }
        return false ; 
        
    }
    
    boolean check(int [][]board , int n ) {
        int N = board.length ;  
        for(int i = N-1 ; i >= n-1 ; i -- ) {
            for(int j = 0 ; j< N ; j++ ){
                if(board[i][j] == 1 &&  
                ( /* checkRow(board, i , j ) ||  */
                     checkCol(board, i , j )  ||  checkDiagonal(board,i,j) ) ) { // 1 
                    return false; 
                }
            }
        }
        return true;  // true can place . 
    }
    void dfs(int [][]board , int n){
        int N = board.length ;
        if( n == 0 ) {
            // build board 
            ArrayList<String> maze = new ArrayList<String>() ; 
            
            for(int i = 0 ; i < N ; i++ ){
                StringBuilder sb = new StringBuilder() ; 
                for(int j = 0 ; j< N ; j++){
                    sb.append(board[i][j] == 0 ? '.':'Q') ; 
                }
                maze.add(sb.toString()) ;
            }
            rets.add(maze) ; 
            return ;
        }
        for(int i = 0 ; i< N ;i++){
            board[n-1][i] = 1 ; 
            if(check(board,n)){
                dfs(board, n -1 )  ;
            }
            board[n-1][i] = 0 ; 
        }
    }
};

