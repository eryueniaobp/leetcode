/*
 * O(2^n) 利用gray code 的生成规律
 * */
class Solution {
public:
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int num = pow(2,n);
        vector<int> ret;
        for(int i = 0 ;i<num;i++){
            ret.push_back((i>>1)^i); 
        }
        return ret;
    }
};
