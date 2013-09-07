/**
 * factorial representation && lehmer code
 */
class Solution { 
public:
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> nl ;
        for(int i = 1 ;i<=n ;i ++){
            nl.push_back(i); 
        }
        string ret;
        int *factor = new int[n];
        factor[0] = 1; 
        for(int i = 1; i < n ; i ++ ){
            factor[i] = factor[i-1] * i ; 
        }
        k-- ; 
        for(int i = n -1 ; i>0 ; i -- ) {
            int code = k/factor[i];
            k = k%factor[i];
            ret.push_back(nl[code] + '0');
            nl.erase(nl.begin()+code);
        }
        ret.push_back(nl[0] + '0');
        return ret;
    }
};

