/**
 * log(n)
 */
class Solution {
//divide-and-conquer
//classic
public:
	double pow(double x, int n) {
		if (n == 0) return 1.0;
		// Compute x^{n/2} and store the result into a temporary
		// variable to avoid unnecessary computing
		double half = pow(x, n / 2);
		if (n % 2 == 0)
			return half * half;
        return half * half * x; 
	}
};
/* 
 * iterative solution: 
 *   n = 2^k1 + 2^k2 + 2^k3 + ... + 2^kn  k1 > k2 > ... > kn .
 *   1) 先求解 k1 , 则 效率  O(  logn * logn ) 不如上面的效率.
 *   2) 先求解  kn ,则效率 O(logn),跟递归效率一样，但细算起来，是递归的一半  
 *
 *   1) 
double pow2(double x , int n ) {
	    if( n == 0 ) return 1.0 ; 
	     
	    int cur = n ; 
	    double base = x  ; 
	    double ret = 1;  
	    while( cur > 1 ) {
			double cursum = base ; 
	        int pre = cur ; 
	        int now = 1; 
	        while( cur > 1  ) {
	            cur = cur/2 ; 
	            now = now * 2;  
	            cursum = cursum * cursum; 
	        }
	     
	        cur = pre - now; 
	        
	        ret *= cursum ; 
	    }
	    if( cur ==1 ) {
			ret *= base ; 
		}
	    
	    return ret; 
	}
2) 从低位到高位  BEST　Solution !! 
int pow3(int x, int n)
{
    int result = 1;
    while (n > 0) {
        if (n & 1)        // n & 1 等价于 (n % 2) == 1
            result *= x;
        x *= x;
        n >>= 1;        // n >>= 1 等价于 n /= 2
    }
    return result;
}
*/ 

