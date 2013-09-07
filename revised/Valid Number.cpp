class Solution {
public:
    bool isNumber(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int e = 0 ;
        int i = 0 ;
        while(s[i] == ' '){
            i++ ;
        }
        s = s+i ; 
        i=0 ; 
        while(s[i] != ' ' && s[i] != NULL){
            i++;
        }
        if(s[i] != NULL){
            i++;
            while(s[i] == ' ' && s[i]!=NULL){
                i ++ ;
            }
            if(s[i] != NULL ) return false;
        }
        i=0;
        for( ;  s[i]!=NULL &&s[i] != ' '; i++){
            if(s[i] == 'e'){
                e = i ;
            }
        }
        int len = i;
        if(e<=0){
            return isValidNumber(s,0,len,1);
        }
        
        return  isValidNumber(s,0,e,1)&&isValidNumber(s,e+1,len-e-1,0);
    }
    bool isValidNumber(const char*s , int start,int len,int dlen){
        int dot = 0 ,dig = 0 ; 
        s =  s+ start;
        for(int i = 0; i <len ;i++){
            if(s[i] != '+' && s[i] != '-' &&s[i]!='.' && (s[i] < '0' || s[i] >'9')){
                return false;
            }
            if(i>0 && (s[i] == '+' || s[i] == '-' )){
                return false;
            }
            if(s[i] == '.'){
                dot ++ ;
            }
            if(dot > dlen){
                return false;
            }
            if(s[i] >= '0' && s[i] <='9'){
                dig++;
            }
        }
        return dig>0;
    }
};


