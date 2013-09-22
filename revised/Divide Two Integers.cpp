/**
 *  A = B*C = B*(2^k1+2^k2+.... + 2^kn) 
 *  时间复杂度 
 *  log(C) * log(C)  C最大为 INT_MAX 32位 所以效率还是可以的
 *
 *  todo : improve to Log(c)  
 */ 
class Solution {
public:
    int divide(int dividend, int divisor) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		long long div=dividend,sor=divisor;
		bool isNeg=(div<0&&sor>0)||(div>0&&sor<0);
		div=div<0?-div:div;
		sor=sor<0?-sor:sor;
		int ans=0;
		while(div>=sor)
		{
			int c=count(div,sor);
			ans+=(1<<c);
			div-=sor<<c;
		}
		return isNeg?-ans:ans;
	}
	int count(long long n,long long d)
	{
		if ( d>n)
			return 0;
		int c=0;
		while( ( n>>1) >= (d<<c) )
			c++;
		return c;
	}
};

