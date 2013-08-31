class Solution {
public:
    int maxProfit(vector<int> &a) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int prevIdx = 0;
        int res = 0;
        
        for (int i = 1; i < a.size(); ++i)
        {
            if (a[i] > a[prevIdx])
            {
                res += a[i] - a[prevIdx];
                
            }
            prevIdx = i;
        }
        
        return res;
    }
};

