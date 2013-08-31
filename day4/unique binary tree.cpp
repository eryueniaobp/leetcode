class Solution {
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n == 0 ) return 0;
        vector<int> v(n+1,0);
        v[0] = 1;
        v[1] = 1 ;
        v[2] = 2;
        for(int i = 3; i<=n ; i++)
            for(int j = 0 ; j<i ;j ++){
                v[i] += v[j]*v[i-1-j];
            }
        return v[n];
    }
};

