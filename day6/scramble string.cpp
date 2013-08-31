/**
 * time complexit: O(n^3) 
 * 采用前一个版本的递归写法 +　状态保存，也是这个复杂度，只是没有这个代码好看
 */
class Solution {
    bool tag[100][100][100];
public:
    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s1.size() ; 
        if(len  !=  s2.size() ) {
            return false;
        }
        if(len == 0 ) return true;
        for(int i = 0 ; i< len ;i ++ ) 
            for(int j = 0 ;j < len ; j++ ) {
                tag[0][i][j] = ( s1[i] == s2[j] ) ;
            }
        for(int k =1 ;  k < len ; k ++ ) 
            for(int i = len -1 - k  ; i >= 0 ; i -- )
                for(int j = len -1 - k ; j >= 0 ; j-- ){
                    bool b = false;
                    for(int m = 0 ; m < k && !b ; m ++ ) {
                        b = ( tag[m][i][j] && tag[k-m-1][i+m+1][j+m+1]) || ( tag[m][i][j+k -m] && tag[k-m-1][i+ m +1 ][j] ) ;
                    }
                    tag[k][i][j] = b ; 
                 }
        return tag[len-1][0][0];
    }
};


