/**
 * O(n) 扫描一遍
 */
class Solution {
    unordered_map<char,int> r2iv;
public:
    Solution::Solution(){
        r2iv['I'] = 1 ;
        r2iv['V'] = 5; 
        r2iv['X'] = 10 ;
        r2iv['L'] = 50 ;
        r2iv['C'] = 100 ;
        r2iv['D'] = 500 ;
        r2iv['M'] = 1000 ;
    }
    int romanToInt(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size = s.size() ;
        if(size == 0 ) {
            return 0;
        }
        int result = 0 ; 
        int sub = r2iv[s[0]]; 
        int last = sub;
        for(int i = 1 ; i< size; i++) {
            int curv = r2iv[s[i]];
            if(curv == last){
                sub += curv;
            }else if( curv < lastv){
                result += sub;
                sub = curv; 
            }else{
                sub = curv -sub;
            }
            last = curv;
        }
        result += sub;
        return result;
    }
};

