/**
 * O(n)
 */
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len  = 0 ,plen = 0 ;
        int i = 0 ;
        while(s[i] != NULL ){
            while(s[i] != NULL && s[i] != ' ' ) {
                i ++ ; 
                len ++ ;
            }
            if(s[i] == ' '){
                plen = len ;
            }
            while(s[i] == ' ' ){
                i++ ;
                len = 0 ;
            }
            
        }
        if(len == 0 && plen != 0 ) return plen;
        return len;
    }
};

