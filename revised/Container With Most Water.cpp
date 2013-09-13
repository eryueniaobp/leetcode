/**
 * O(n)
 */
class Solution {
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0;
        int j = height.size() - 1;
        
        int ret = 0;
        while(i < j)
        {
            int area = (j - i) * min(height[i], height[j]);
            ret = max(ret, area);
            
            if (height[i] <= height[j])
                i++;
            else
                j--;
        }
        
        return ret;
    }
};

