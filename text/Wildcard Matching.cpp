/**
 * 只能过小数据
 */
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //memset(tag,0,1000*1000*sizeof(int));
        if(s == NULL || p == NULL ) return false;
        if(*p == '\0' ) return *s == '\0';
        if(*p == '*' ){
            while(*p == '*') ++p;
            while(*s != '\0'){
                if(isMatch(s,p)) return true;
                ++s;
            }
            return isMatch(s,p);
        }else if((*s != '\0' && *p == '?') || *p == *s){
            return isMatch(s+1,p+1);
        }
        return false;        
    }
};
/**
 * 可以过大数据
 */
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        bool star = false;
        const char* starPtr = NULL;
        const char* savePtr = NULL;
        while(*s != '\0')
        {
            if(*p == '?') s++, p++;
            else if(*p == '*')
            {
                while(*p == '*') p++;
                p--;
                starPtr = p;
                p++;
                savePtr = s;
                star = true;
            }
            else 
            {
                if(*s == *p) s++, p++;
                else
                {
                    if(star == true) s = ++savePtr, p = starPtr+1;//depend on star
                    else return false;
                }
            }
        }
        while(*p == '*') p++;
        return (*s == '\0' && *p == '\0');
    }
};

