/**
 * O(n) 一个经典算法  http://blog.csdn.net/ggggiqnypgjg/article/details/6645824  Manacher Alg
 * Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring
 */
class Solution {
    
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s.size() == 0)
            return "";
        string str(s.size() * 2 + 1,'\0')  ;
        str[0] = '#'  ;
        for(int i = 0 ; i< s.size() ; i++ ) {
            str[i*2 + 1 ] = s[i];
            str[i*2 + 2 ] = '#' ; 
        }
        vector<int> tag(s.size()*2 + 1 ) ;         

        int mr = 0 ; 
        int cur = 0 ; 
        for(int i = 0 ; i < s.size() *2 +1 ; i ++ ){
            if(mr > i ) {
                tag[i] = min ( tag[2*cur -i ] ,tag[cur] - ( i-cur) ) ; 
            }else{
                tag[i] = 1; 
            }
            while(i-tag[i]>=0 && str[i + tag[i]] == str[i - tag[i] ] ) {
                tag[i] ++ ;
            }
            if( tag[i] + i > mr ) {
                mr = tag[i] + i ; 
                cur = i ;
            }
        }
        int max = INT_MIN; 
        int pos = -1; 
        for(int i = 0 ; i < tag.size() ; i++ ) {
            if(tag[i] > max ) {
                pos =  i ; 
                max = tag[i] ; 
            }
        }
        return s.substr( (pos-1)/2 - max/2 + 1 , max - 1 ) ;
    }
};


