class Solution {
private:
    vector<int> _mark;
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (T.size() == 0 || S.size() == 0)
            return "";
            
        _mark.assign(256,INT_MAX);
        for(int i = 0; i < T.size(); i++)
        {
            _mark[T[i]] = (_mark[T[i]] == INT_MAX?1:(_mark[T[i]]+1));
        }
        int count = T.size();
        
        int start = 0;
        int minSize = INT_MAX;
        int minStart;
        for(int end = 0; end < S.size(); end++)
        {
            if (_mark[S[end]] != INT_MAX )
            {
                _mark[S[end]] -- ;
                if (_mark[S[end]] >= 0)
                    count--;
            }
            
            if (count == 0)
            {
                while(true)
                {
                    if (_mark[S[start]] != INT_MAX )
                    {
                        if (_mark[S[start]] < 0){
                            _mark[S[start]]++;
						}else{
                            break;
						}
                    }
                    start++;
                }
                if (minSize > end - start + 1)
                {
                    minSize = end - start + 1;
                    minStart = start;
                }
            }
        }
        
        if (minSize == INT_MAX)
            return "";
        
        string ret(S, minStart, minSize);
        
        return ret;        
    }
};


