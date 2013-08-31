class Solution {
    int tag[1000][1000];
public:
    int dfs(int m,int n) {
        if(m == 1 || n ==1 ) return 1;
        if(tag[m][n] != 0 ) {
            return tag[m][n];
        }
        int sum = 0 ;
        for(int i = 1 ; i <= n ; i ++ ) {
            sum += uniquePaths(m-1,i);
        }
        tag[m][n] = sum; 
        return sum;
    }
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        memset(tag,0,1000*sizeof(int));
        return dfs(m,n);
    }
};

