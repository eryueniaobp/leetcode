/**
 * 模拟运算即可 
 * O(m*n)
 * 并不需要两位两位的计算
 */
class Solution {
public:
    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0 ;
        if(num1.size() < num2.size() ) {
            swap(num1,num2);
        }
        if(num1 == "0" ||num2 == "0" ) return "0";
        vector<int> ivec(100000,0);
        int carry =  0 ;
        for(int i = 0 ; i< num2.size() ; i++ ){
            int k = i ;
            for(int j = 0 ; j<num1.size(); j++){
                int a = num2[num2.size()-1-i] - '0' ;
                int b = num1[num1.size()-1-j] - '0' ; 
                int m = a * b + ivec[k+j]+carry;
                ivec[k+j] = m%10;
                carry = m/10;
            }
            if(carry > 0 ){
                ivec[k+num1.size()]  = carry;                   
            }
            carry = 0 ;
        }
        int len = 0;
        for( i = 100000 -1; i>=0 ; i--){
            if(ivec[i] != 0 ){
                break;
            }
        }
        len = i + 1;
        if(carry > 0 ){
            ivec[i+1] = carry;
            len = i + 2;
        }
        string ret ;
        for( i = len - 1; i>= 0 ; i--){
            ret.push_back(ivec[i] + '0');
        }
        return ret;

    }
};

