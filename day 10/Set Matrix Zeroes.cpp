class Solution {
    int mtag[10000];
    int ntag[10000];
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = matrix.size();
        int n = matrix[0].size();
        memset(mtag,1,m*sizeof(int));
        memset(ntag,1,n*sizeof(int));
        for(int i = 0 ; i< m ; i ++ ){
            for(int j =  0 ;j<n ;j++){
                if(matrix[i][j] == 0 ){
                    mtag[i] = 0 ;
                    ntag[j] = 0 ;
                }
            }
        }
        for(int i = 0 ; i < m ; i ++ ) {
            for(int j = 0 ;j< n ; j++){
                if(mtag[i] == 0 || ntag[j] == 0 ){
                    matrix[i][j] = 0 ;
                }
            }
        }

    }
};

