class Solution {
public:
    int num(int n ) {
    	return n <= 0 ? INT_MAX : n ;
	}
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(x == 0 ) return 0;
        if(x ==1 ) return  1;
        int i = 1 ,k = 0 ;
        while((k=num(i*i )) <= x && k != INT_MAX ) {
            i = i *  2 ;
        }
        int j  = i/2; 
        while(j < i && (k=num(j*j)) <=x && k != INT_MAX){
            j = j +1; 
        }
        return j-1;
    }
};


