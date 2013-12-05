/**
 * O(n) 
 * 寻找第一个 tmark[S[start]]>0 && mark[S[start]] == 0 的位置
 */
class Solution {
private:
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (T.size() == 0 || S.size() == 0)
            return "";
            
        int mark[256] = {0} , tmark[256] = {0} ;
        for(int i = 0; i < T.size(); i++) {
            mark[T[i]] ++  ;
            tmark[T[i]] ++ ;
        }
        int count = T.size();
        
        int start = 0;
        int minSize = INT_MAX;
        int minStart;
        for(int end = 0; end < S.size(); end++) {
            if (tmark[S[end]] >= 1){
                if(mark[S[end]] > 0 ) count -- ;
                mark[S[end]] -- ;
            }
            if (count == 0) {
                while(true){
                    if(tmark[S[start]] == 0 ) start ++ ; 
                    else{
                        if(mark[S[start]] == 0 ) break; // [start,end] 是一个包含区间 且  S[start] S[end]都在T中
                        mark[S[start]] ++ ;
                        start ++ ; 
                    }
                }
                /*while(tmark[S[start]] == 0 || mark[S[start]] < 0 ){
                    if(mark[S[start]] < 0 ) mark[S[start]] ++ ;
                    start++;
                }*/
                if (minSize > end - start + 1){
                    minSize = end - start + 1;
                    minStart = start;
                }
            }
        }
        
        if (minSize == INT_MAX)
            return "";
        
        return string(S, minStart, minSize);        
    }
};
