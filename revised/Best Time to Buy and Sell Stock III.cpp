/**
 * O(n)
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

