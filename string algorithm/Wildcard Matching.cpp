class Solution {
    int tag[1000][1000] ;
public:
    bool isWildCard(const char c ){
        return c == '?' || c == '*'; 
    }
    bool dfs(const char *s,const char *p,int is,int ip){
        if(tag[is][ip] == 1) return true;
        if(tag[is][ip] == 0) return false;
        if(s[is] == NULL && p[ip] == NULL ) return true;
        if(s[is] == NULL ){
            if(p[ip] == '*'){
                tag[is][ip]=dfs(s,p,is,ip+1);
                return tag[is][ip];
            }
            tag[is][ip] = 0;
            return false;
        }
        if(s[is] == p[ip]  && !isWildCard(p[ip])) {
            tag[is][ip] = dfs(s,p,is+1,ip+1);
            return tag[is][ip];
        }
        if(s[is] != p[ip] && !isWildCard(p[ip])){
            tag[is][ip] = 0;
            return false;
        }
        if(p[ip] == '?'){
            tag[is][ip]= dfs(s,p,is+1,ip+1);
            return tag[is][ip];
        }
        if(p[ip] == '*' ){
            int i = is;
            int tip = ip ;
            for( ; s[i]!=NULL  ; i ++ ){
                while(p[tip+1] == '*') {
                    tip++;                     
                };
                if(dfs(s,p,i,tip+1)){
                    tag[i][ip] = 1;
                    return true;
                }
                tag[i][ip] = 0;
            }
            tag[is][ip] = dfs(s,p,i,ip+1);
            return tag[is][ip];
        }
        
        
    }
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //memset(tag,0,1000*1000*sizeof(int));
        for(int i = 0 ;i<1000 ;i ++ )
            for(int j = 0 ;j<1000 ; j++){
                tag[i][j] = -1;
            }
        return dfs(s,p,0,0);        
    }
};

