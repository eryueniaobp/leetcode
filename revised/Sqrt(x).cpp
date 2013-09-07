/**
 * 牛顿迭代法
 */
class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        double ans = x;
        
        while(abs(ans * ans - x) > 0.0001)
        {
            ans = (ans + x / ans) / 2;
        }
        
        return (int)ans;
    }
};

