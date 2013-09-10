class Solution {
    int l_ ;
    int r_; 
    vector<string> rets_;
    vector<char> ret_;
public:
    string build(vector<char> &a){
        string s ;
        for(int i = 0 ; i< a.size() ; i ++){
            s.push_back(a[i]);
        }
        return s;
    }
    bool check(vector<char> ret){
		stack<char> cst;
		for(int i = 0 ; i<ret.size() ; i ++){
			if(ret[i] == '('){
				cst.push('(');
			}else{
				if(!cst.empty())
				cst.pop();
				else{
					return false;
				}
			}
		}
		return !cst.empty() && cst.top() == '(';
		
	}
    void dfs(int l,int r,int n){
        if( l == n ) {
            if( r < n ) {
                ret_.push_back(')');
                dfs(l,r+1,n);
                ret_.pop_back();
                return ;
            }else{
                rets_.push_back(build(ret_));
                return;
            }
        }
        ret_.push_back('(');
        dfs(l+1,r,n);
        ret_.pop_back();
        if( check(ret_) ){
            ret_.push_back(')');
            dfs(l,r+1,n);
            ret_.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        l_ = 0 ;
        r_ = 0 ; 
        rets_.clear();
        ret_.clear();
        dfs(l_,r_,n);
        return rets_;
    }
};

