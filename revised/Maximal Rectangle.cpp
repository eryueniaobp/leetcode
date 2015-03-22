/**
 * O(m*n ) 的总效率
 * Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.  

 * http://blog.csdn.net/kenden23/article/details/17503899 clear statement.
 * based on max histogram 
 */
class Solution {
    int left[1000];
    int right[1000];
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l = matrix.size();
        if(l == 0 ) return 0 ;
        int c = matrix[0].size();
        deque<int> oned; 
        vector<vector<int> >tag(l);
        for(int i = 0 ; i< l ; i++){
            int j = 0 ;
            while(j<c){
                char ch = matrix[i][j];
                if(ch == '1' ){
                    oned.push_back(j);
                    j++;
                }else{
                    while(!oned.empty()){
                        int s = oned.size();
                        int k = oned.front();
                        oned.pop_front();
                        tag[i].push_back(s);
                    }
                    tag[i].push_back(0);
                    j++;
                }
            }
            while(!oned.empty()){
                tag[i].push_back(oned.size());
                oned.pop_front();
            }
        }
        int max = INT_MIN;
        for(int i =  0 ; i<c ; i ++ ){
           for( int j = 0 ; j < l ;j ++ ){
                left[j] = right[j] = j ; 
           }
           for( int j = 0 ; j< l ; j ++ ) {
               while( left[j] > 0 && tag[j][i] <= tag[ left[j] - 1 ] [i] ) {
                   left[j] = left [ left[j] - 1 ] ; 
               }
           }
           for ( int j = l-1 ; j>=0 ;j -- ) {
               while (right[j] < l-1 && tag[j][i] <= tag[ right[j] + 1 ] [i] ) {
                   right[j] = right[ right[j] + 1 ] ;
               }
           }
           // tag[j][i] line-j , col-i   num of 1s    
           // for example , the first col is always 1 . then tag[0][0] = 1 tag[1][0] = 2 tag[2][0] = 3 
           // also based on the histogram 
           for( int  j = 0 ; j < l ; j++ ){
               int tmp = tag[j][i] * ( right[j] - left[j] + 1 ) ; 
               if(tmp > max ) {
                   max =tmp ;
               }
           }
        }
        return max;
    }
};

// A clear solution based on maximal histogram 
int maximalRectangle(vector<vector<char> > &matrix) 
	{
		if (matrix.empty() || matrix[0].empty()) return 0;
		vector<int> height(matrix[0].size()+1);
		int max_area = 0;
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix[0].size(); j++)
			{
				if (matrix[i][j] == '1') height[j]++;
				else height[j] = 0;
			}
			max_area = max(max_area, maxHistogram(height));
		}
		return max_area;
	}
	int maxHistogram(vector<int> &height)
	{
		int ans = 0;
		stack<int> stk;
		for (int i = 0; i < height.size(); )
		{
			if (stk.empty() || height[stk.top()] < height[i]) stk.push(i++);
			else
			{
				int idx = stk.top();
				stk.pop();
				ans = max(ans, (stk.empty()? i:i-stk.top()-1)*height[idx]);
			}
		}
		return ans;
	}
