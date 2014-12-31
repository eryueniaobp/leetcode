/**
 * O(n)
 * Note: You can sell and buy at the same day  . 
 */
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size = prices.size();
        if (size <= 1)
            return 0;
        
        vector<int> leftIncomes(size, 0);
        vector<int> rightIncomes(size, 0);
        
        int min = prices[0];
        for (int i=1; i<size; i++) {
            if (prices[i] < min)
                min = prices[i];
            if (prices[i] - min > leftIncomes[i-1])
                leftIncomes[i] = prices[i] - min;
            else
                leftIncomes[i] = leftIncomes[i-1];
        }
        
        int max = prices.back();
        for (int i=size-2; i>=0; i--) {
            if (prices[i] > max)
                max = prices[i];
            if (max - prices[i] > rightIncomes[i+1])
                rightIncomes[i] = max - prices[i];
            else
                rightIncomes[i] = rightIncomes[i+1];
        }
        
        int profit = 0;
        for (int i=0; i<size; i++) {
            if (leftIncomes[i] + rightIncomes[i] > profit)
                profit = leftIncomes[i] + rightIncomes[i];
        }
        
        return profit;
    }
};
/**
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.
*/
class Solution {
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    public int maxProfit(int[] prices) {
        // write your code here
        int []v = new int[prices.length] ; 
        int min = Integer.MAX_VALUE;
        int dmax = -1 ; 
        for(int i = 0 ; i< prices.length ; i ++ ){
            if( prices[i] < min ){
                min = prices[i] ; 
            }
            if(prices[i] - min > dmax ){
                dmax = prices[i] - min ; 
            }
            v[i] = dmax ; 
        }
       
        int profit = 0  ; 
        int max = Integer.MIN_VALUE;
        dmax = -1 ; 
        for(int i = prices.length -1 ; i>= 0 ; i-- ) {
            if( prices[i] > max ){
                max = prices[i] ; 
            }
            int diff = max - prices[i] ; 
            if ( dmax < diff) {
                dmax = diff ; 
            }
            
            if( dmax + v[i] > profit) { // note: sell and buy at the same day
                profit =dmax+v[i] ; 
            }
            
        }
        return profit ;
    }
};
/** Allow 3 transactions at most **/
static int getProfit(int []prices, int start ,int end ){
        int min = Integer.MAX_VALUE;
        int max = 0;

        for(int i = start ; i<end;i++){
            if(prices[i] < min){
                min = prices[i];
            }
            if(prices[i] - min > max ){
                max = prices[i] - min ;
            }

        }
        return max ;
    }
    static int getMaxProfits(int[] prices) {
        int min = Integer.MAX_VALUE;
        int max = 0;
        int []left = new int[prices.length]  ;
        for(int i = 0 ; i<prices.length;i++){
            if(prices[i] < min){
                min = prices[i];
            }
            if(prices[i] - min > max ){
                max = prices[i] - min ;
            }
            left[i] = max ;
        }
        int []right = new int[prices.length]  ;
        int maxv =  0 ;  max = 0 ;
        for(int i = prices.length -1 ; i>= 0 ;i -- ){
            if(prices[i] > maxv ) maxv = prices[i] ;
            if(maxv - prices[i] >  max ){
                max = maxv - prices[i] ;
            }
            right[i] = max ;

        }
        max = left[prices.length-1]; // if max = 0 ,it will be wrong .
        for(int i = 0 ; i < prices.length ; i++){
            for(int j = i + 1 ; j < prices.length ; j++ ) {
                int lmax = left[i] ;
                int rmax = right[j] ;
                int mmax = getProfit(prices, i  , j +1  )  ; // sell and buy at the same day
                if( lmax + rmax  + mmax > max ) {
                    max = lmax + rmax + mmax ;
                }
            }
        }
        return max ;


    }
