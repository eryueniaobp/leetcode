class Solution {
    // solution 1: k - heap          O(m*n *log(k) ) 
    // solution 2: binary search,    O (log(m*n) m )  
    public int findKthNumber(int m, int n, int k) {
        int s = m + n ; 
        m = min(m, n ) ;
        n = s - m ;  
        //  log(m*n + 1) * m 
        int fir = 1 , end = m *n +1 ; 
        while (fir < end){
            int mid = (fir+end)/2 ;
            
            
            int k1 = 0 ;
            for(int i = 1 ; i<= m ; i++){
                k1 += min(mid/i, n );
            }
            
            
            if ( k1 >= k) 
                end = mid ; // decrease the target! 
            else{
                fir = mid + 1 ;
            }
        
        }
        return fir;
    }
}
