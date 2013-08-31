class Solution {
public:
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int pd = 1;
        int i = 1; 
        string ret;
        for(  i = 1 ; i<= n ; i++ ){
            if( k > pd* i ){
                pd = pd * i ;
                ret.push_back(i+'0');
                continue;
            }
            break;
        }
        cout<<ret<<endl;
        int j = (k - pd) / pd ;   // pd < i ;
        
        int rem = (k-pd) % pd ; 
        int 
        
    }
};

