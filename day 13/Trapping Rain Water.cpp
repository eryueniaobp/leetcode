class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> left(n);
        int maxHeight = 0;
        for(int i = 0; i < n; i++)
        {
            left[i] = maxHeight;
            maxHeight = max(maxHeight, A[i]);
        }
        
        vector<int> right(n);
        maxHeight = 0;
        for(int i = n - 1; i >= 0; i--)
        {
            right[i] = maxHeight;
            maxHeight = max(maxHeight, A[i]);
        }
        
        int water = 0;
        for(int i = 0; i < n; i++)
        {
            int height = min(left[i], right[i]) - A[i];
            if (height < 0)
                height = 0;
            water += height;
        }
        
        return water;
    }
};

