/*
 * O(n) n 是所有数字的个数
 * */
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans(numRows);
		for(int i = 0; i < numRows; ++i)
			ans[i].assign(i+1, 1);
		//
		for(int i = 0; i < numRows; ++i)
		{
			for(int j = 1; j <= i-1; ++j)
				ans[i][j] = ans[i-1][j-1]+ans[i-1][j];

		}
		//
		return ans;
    }
};

