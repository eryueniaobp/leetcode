class Solution {
    int count[256];
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        memset(count,0,256*sizeof(int));
        int size = s.size();
        if(size == 0 ){
            return 0;
        }
        int max = INT_MIN;
        int cur = 0;
        for(int i = 0 ;i<size;i++){
            if(count[s[i]] + 1 > 1){
                memset(count,0,256*sizeof(int));
                count[s[i]] = 1;
                int j = 0 ;
                for( j = i-1; j>=0 ; j--){
                    if(s[j] == s[i] ){
                        break;
                    }
                    count[s[j]] = 1;
                }
                cur = i - j;
            }else{
                count[s[i]] ++ ;
                cur ++ ;
            }
            if(cur > max ){
                max = cur;
            }
        }
        return max;
    }
};


