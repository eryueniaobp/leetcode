class Solution {
    vector<string> _ret;
    int _size;
public:
    string buildLine(vector<string> &line,int L){
        int sum = 0 ;
        for(int i = 0 ; i<line.size() ; i++){
            sum += line[i].size();
        }
        sum = L - sum ;
        int space = sum ; 
        if(line.size() > 1 ){
            space = space/(line.size()-1);
        }
        string sstr(space,' ');
        string ret;
        int  i = 0 ;
        for(  i = 0 ; i<line.size() -1 ; i++ ){
            ret.append(line[i]);
            ret.append(sstr);
        }
        ret.append(line[i]);
        return ret;
    }
    bool dfs(vector<string> &words,int L,int start){
        if(start >=_size ) return true;
        int sum =  0 ; 
        int i =  start; 
        vector<string> svec;
        for(; i< _size ; i++){
            string node = words[i];
            sum += node.size()+1;
            if(sum > L + 1 ) {
                break;
            }
            svec.push_back(node);
        }
        if( i == _size ) {
            return true;
        }
        if( i == start ) {
            return false;
        }
        start = i-- ;
        while( i-->0 ){
            if(dfs(words,L,start)){
                _ret.push_back(buildLine(svec,L));
                return true;
            }
            _ret.pop_back();
            start = i+1;
            svec.pop_back();
        }
        
    }
    vector<string> fullJustify(vector<string> &words, int L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        _ret.clear();
        _size = words.size();
        dfs(words,L , 0  ) ;        
        return _ret;
    }
};

