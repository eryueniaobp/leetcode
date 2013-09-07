/**
 * 直接利用GrayCode的规律  或者 dfs 都可以做
 */
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = pow(2,S.size()) ;         
        sort(S.begin(),S.end(),less<int>());
        vector<vector<int> > ret;
        for(int i = 0 ; i< n ; i++ ) {
            int k = (i>>1)^i;
            vector<int> sv;
            int j = 0 ;
            while(k>0){
                if(k&0x01){
                    sv.push_back(S[j]); 
                }   
                k = k>>1;
                j++;
            }
            ret.push_back(sv);
        }
        return ret;
    }
};

class Solution {
    int size_;
    vector<vector<int> > ret_;
    vector<int> set_;
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        size_ = S.size();
        sort(S.begin(),S.end(),less<int>());
        ret_.clear();
        set_.clear();
        dfs(S,0);  
        return ret_;
    }
    void dfs(vector<int> &S, int l){
        if(l == size_ ){
            ret_.push_back(set_);
            return;
        }
        for(int i =  l ; i<=size_ ;i++){
            if(i<size_){
                set_.push_back(S[i]);
                dfs(S,i+1);
                set_.pop_back();
            }else{
                ret_.push_back(set_);
            }
        }
    }
};



