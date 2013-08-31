class Solution {
    int _l ;
    int _r; 
    vector<string> _rets;
    vector<char> _ret;
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
                _ret.push_back(')');
                dfs(l,r+1,n);
                _ret.pop_back();
                return ;
            }else{
                _rets.push_back(build(_ret));
                return;
            }
        }
        _ret.push_back('(');
        dfs(l+1,r,n);
        _ret.pop_back();
        if( check(_ret) ){
            _ret.push_back(')');
            dfs(l,r+1,n);
            _ret.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        _l = 0 ;
        _r = 0 ; 
        _rets.clear();
        _ret.clear();
        dfs(_l,_r,n);
        return _rets;
    }
};

