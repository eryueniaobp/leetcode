class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(x < 10 && x > -10){
            return x;
        }
        int flag;

        if(x > 0){
            flag = 1;
        }else{
            flag = -1;
            x = -x;
        }

        int temp = 0;

        while(x != 0){
            temp = temp * 10 + x % 10;
            x = x / 10;
        }
        return flag * temp;
        
    }
};

