class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size = digits.size();
        int k = 1  ;
        vector<int> ret;
        
        for(int i = size - 1; i>= 0 ; i--){
            int a = digits[i] + k;
            ret.push_back(a%10);
            k = a/10;
        }
        if(k>0){
            ret.push_back(k);
        }
        size = ret.size();
        for(int i = 0 ;i<size/2 ;i++){
            swap(ret[i],ret[size-1-i]);
        }
        return ret;
    }
};


