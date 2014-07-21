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
 * n = 2^k1 + 2^k2 + 2^k3 + ... + 2^kn  k1 > k2 > ... > kn . 效率  O(  logn * logn ) 不如上面的效率.
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

*/ 

