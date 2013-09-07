/**
 * 动归解决 O(n)
 */
class Solution {
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size = s.size();
        if(size == 0 ){
            return  0;
        }
        vector<int> iv(size);
        iv[0] = (s[0] == '0'?0:1);
        if(iv[0] == 0 ){
                 return 0 ;
        }
        for(int i = 1 ;i<size;i++){
            if(s[i-1] == '0' && s[i] == '0') {
                iv[i] = 0 ; 
            }else if(s[i-1] == '0' ){
                iv[i] = iv[i-1];
            }else if(s[i]  == '0' ){
                int n = (s[i-1] -'0') *10 + s[i] -'0' ;
                if(n>26){
                    iv[i] = 0 ;
                }else{
                    iv[i] = (i-2<0?1:iv[i-2]);
                }
            }else{
               
                int n = (s[i-1] -'0') *10 + s[i] -'0' ;
                if(n>26){
                    iv[i] = iv[i-1];
                }else{
                    iv[i] = iv[i-1] + (i-2<0?1:iv[i-2]);
                }
            }
        }
        return iv[size-1];
    }
};

