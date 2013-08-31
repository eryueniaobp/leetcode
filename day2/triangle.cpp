class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (triangle.size() == 0)
            return 0;
            
        vector<int> f(triangle[triangle.size()-1].size());
        
        f[0] = triangle[0][0];
        for(int i = 1; i < triangle.size(); i++)
            for(int j = triangle[i].size() - 1; j >= 0; j--)
                if (j == 0)
                    f[j] = f[j] + triangle[i][j];
                else if (j == triangle[i].size() - 1)
                    f[j] = f[j-1] + triangle[i][j];
                else
                    f[j] = min(f[j-1], f[j]) + triangle[i][j];
                    
        int ret = INT_MAX;
        for(int i = 0; i < f.size(); i++)
            ret = min(ret, f[i]);
            
        return ret;       
    }
};

