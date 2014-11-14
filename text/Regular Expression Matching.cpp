/**
 * 递归版本 
 */
class Solution {
public:
	bool isMatch(const char *s, const char *p) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function    

		if( 0 == *p) return 0 == *s;

		if(*(p+1) != '*')
		{
			if(*p == *s || (*p) == '.' && (*s) != 0)
			{
				return isMatch(s+1, p+1);
			}
			return false;
		}
		else
		{
			while(*p == *s || ((*p) == '.' && (*s) != 0)) // 处理 a*覆盖到的部分 * = 0 开始 到最大覆盖的部分 
			{
				if(isMatch(s, p + 2))
				{
					return true;
				}
				s++;
			}
			return isMatch(s, p + 2); // *s != *p 跳过 a*覆盖的部分 ，比较后面的可行性

		}
		
	}
};
/**
 *  + * 的情况 
 */
bool match(const char * p , const char *s){
    if ( 0 == *p && 0 == *s ) return true; 
    
    if( *(p+1) != '*' && *(p+1) != '+' ) {  // ab* a 
        return (*p == *s ) && match( p+1 ,s+1 ) ; // match( "b*",\0) 
    }else if( *(p+1) == '*' ) {
        while(  *p == *s ) { 
            if ( match ( p + 2 ,s ) ) {
                return true; 
            }
            s ++ ; 
        }
        return match(p+2, s ) ; // pass the current star.  /// match ( null , null) ; true. 
    }else if( *(p+1) == '+' ) {  // here ! 
        if(*p != *s ) return false; // must match one 
        while ( *p == *s ) {
            s++ ;  /// 
            if( match ( p +2 ,s) ) return true; // match("ab" , "ab" ) ;
        } 
        return match(p+2 , s ) ;      // match ( "ab","b") ; 
    }else{
        
    } 
}

/**
 * DP 版本
 */
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        int len1 = 0;
        for(const char* q = s; *q != '\0' && q != NULL; ++q) len1++;
        int len2 = 0;
        for(const char* q = p; *q != '\0' && q != NULL; ++q) len2++;
        
        vector<vector<bool> > f(len1+1, vector<bool>(len2+1, false));
        f[0][0] = true;
        for(int i = 0; i <= len1; ++i)
        {
            char preChar = '\0';
            int preIdx = 0;
            for(int j = 1; j <= len2; ++j)
            {
                if(i >= 1 && (p[j-1] == '.' || s[i-1] == p[j-1])) f[i][j] = f[i-1][j-1];
                else if(p[j-1] == '*')
                {
                    if(i >= 1 && (preChar == s[i-1] || preChar == '.')) f[i][j] = f[i-1][j] || f[i][j-1];
                    f[i][j] = f[i][j] || f[i][preIdx];
                }
                if(p[j-1] != '*') preChar = p[j-1], preIdx = j-1;
            }
        }        
        
        return f[len1][len2];
    }
};


