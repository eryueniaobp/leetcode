/**
 * O(n)
 * i ~ first[i]  first[i] 第一次出现重复的位置 
 * s[i] = s[next[i]]  
 * s[k] = s[first[i]] , i<=k < first[i] 
 */
class Solution {
    int hash[256];
    int first[1000];
    int next[1000] ;
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //memset(count,0,256*sizeof(int));
        int size = s.size();
        if(size == 0 ){
            return 0;
        }
        fill(hash,hash+256,size) ;
        first[size-1] = size;
        next[size-1] = size;
        hash[s[size-1]] = size-1;
        for(int i = size-2 ; i >= 0; i -- ){
            next[i] = hash[s[i]] ; 
            hash[s[i]] = i ; 
            if( next[i] < first[i+1] ){
                first[i] = next[i];
            }else{
                first[i] = first[i+1] ; 
            }
        }

        int max = INT_MIN;
        for(int i = 0 ;i<size;i++){
            if(first[i] - i > max ){
                max = first[i] - i ;
            }
        }
        return max;
    }
};



