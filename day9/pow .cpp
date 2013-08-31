class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n == 0 ) return 1.;
        if(n == INT_MIN ) return 1/(pow(x,INT_MAX)*x);
        if(n < 0 ) return 1/pow(x,-n);
         
        if( n == 1 ) return x;
        double b = x; 
        int i = 2;
        while(n/i>0 ){
            x = x*x;
            if(n/(i*2) > 0 ) {
                i = i*2 ;
            }else{
                break;
            }
        }
        return x * pow(b,n-i);
    }
};



