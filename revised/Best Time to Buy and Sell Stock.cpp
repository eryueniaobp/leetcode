/**
 * O(n)
 */
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int min = INT_MAX; 
		int max = 0;
		for(int i = 0 ; i<prices.size();i++){
			if(prices[i] < min){
				min = prices[i];
			}
			if(prices[i] - min > max ){
				max = prices[i] - min ;
			}	
		}
		return max;		
    }
};

