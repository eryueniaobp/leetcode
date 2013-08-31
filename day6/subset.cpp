class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = pow(2,S.size()) ;         
        sort(S.begin(),S.end(),less<int>());
        vector<vector<int> > ret;
        for(int i = 0 ; i< n ; i++ ) {
            int k = (i>>1)^i;
            vector<int> sv;
            int j = 0 ;
            while(k>0){
                if(k&0x01){
                    sv.push_back(S[j]); 
                }   
                k = k>>1;
                j++;
            }
            ret.push_back(sv);
        }
        return ret;
    }
};

