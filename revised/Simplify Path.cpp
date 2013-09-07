/**
 * 简单的模拟算法
 */
class Solution {
public:
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0 ; 
        deque<string> dstr;
        string tmp ; 
        while( i < path.size() ) {
            if(path[i] == '/'){
                i++;
                continue;
            }
            if(path[i] == '.'){
                if(i+1 >= path.size() ) { 
                    i++;
                    continue;
                }
                if(path[i+1] == '.' ){
                    if(!dstr.empty()) dstr.pop_back();
                    i = i+2;
                    continue;
                }
                if(path[i+1] == '/'){
                    i++ ;
                    continue;
                }
                tmp.push_back('.');
                i++ ; 

            }
            int j = i ; 
            while(j<path.size() && path[j] != '/' && path[j] != '.' ){
                tmp.push_back(path[j]);
                j++;
            }
            dstr.push_back(tmp);
            tmp.clear();
            i = j ;

        }
        string ret = "/" ;
        while(!dstr.empty()){
            ret.append(dstr.front());
            dstr.pop_front();
            if(dstr.size() > 0 ) {
                ret.append("/");
            }
        }
        return ret;
    }
};



