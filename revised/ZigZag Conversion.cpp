/**
 * O(n) 扫描一遍
 */
class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        int size = s.size();
        if(size == 0 ) {
            return "";
        }
        if(nRows ==1 ){
            return s ;
        }
        string ret(size,0);
        int i = 1 ;
        int j = 0 ;
        while ( i <= size ){
            ret[j++] = s[i-1];
            i = i + 2*nRows - 2 ;
        }
        for(i = 2 ; i< nRows ; i ++ ){
            int k = i ; 
            bool flag = false;
            while(k<=size){
                ret[j++] = s[k-1];
                if(!flag){
                    k = k + 2*(nRows - i ) ; 
                }else{
                    k = k + 2*(i-1);
                }
                flag = !flag;
            }
        }
        i = nRows ;
        while( i <= size){
            ret[j++] = s[i-1];
            i = i + 2*nRows -2;
        }
        return ret;
    }
};

