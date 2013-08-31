class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(x == 0) return true;
        if( x < 0 ) return false;
        int i =  10;
        int j = 1 ;
        int backup = x;
        while(x/10 > 0 ) {
            i = i *10 ;
            j++ ;
            x  = x/10;
        }
        x = backup ; 
        //cout<< "j = " <<  j <<endl;
        int k = 1 ; 
        int l = j ; 
       while( k<=l ){
        	int c1 = x%((int)pow(10.,k))/(int)pow(10.,k-1)  ;
			int c2 = ( x / (int)pow(10.,l-1) ) %( (int) pow(10.,1) ) ; 
		//	cout<<c1<<" "<<c2<<endl;
			if(c1 != c2) break;
            k ++ ;
            l -- ;
            
        }
        if( k>l ){
            return true;
        }
        return false;

    }
};

