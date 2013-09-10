/**
 * Sunday Algorithm 
 * 最坏情况是 O(n*m) 但据说平均情况快得很...
 *
 * KMP 课本上有，这里没有实现一遍了
 */
class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0 ; 
        int hash[256]; 
        memset(hash,-1,sizeof(int)*256);    
        while(needle[i]!=NULL){
            hash[needle[i]] = i ;
            i++;
        }
      //  cout<<"hash ok"<<endl;
        int nlen = i ;
        int hlen = strlen(haystack);
        while(i<=hlen){

            int j = i-1;
            while(j>=0 && haystack[j] == needle[j-(i-nlen)] ){
                j -- ;
            }
            if( i-j == nlen + 1){
                return haystack + j + 1;  
            }
            if(hash[haystack[i]] >= 0 ) {
                i = i + nlen - hash[haystack[i]] ;
            }else{
				i++;
			}
        } 
        return NULL;
        
    }
};

