/**
 * O(n*n) 
 * 每次都填满四周的边界
 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
         // DO NOT write int main() function
        vector<int> ret;
        int m = matrix.size();
        if(m == 0 ) {
            return ret;
        }
        int n = matrix[0].size();
        int startX = 0;
        int startY = 0;
        int endX = m - 1;
        int endY = n - 1;
        
        
        while (startX <= endX && startY <= endY ) {
            fetchNumber(startX, startY, endX, endY, matrix,ret);
            startX++;
            startY++;
            endX--;
            endY--;
        }
        return ret;         
    }
    void fetchNumber(int startX,int startY,int endX,int endY,vector<vector<int>> & matrix,vector<int> &ret){
        for (int i = startY; i <= endY; i++) {
            ret.push_back(matrix[startX][i]);
        }
        for (int i = startX + 1; i <= endX; i++) {
            ret.push_back(matrix[i][endY]);
        }

        for (int i = endY - 1; i >= startY && startX<endX ; i--) {
            ret.push_back(matrix[endX][i]);
        }

        for (int i = endX - 1; i >= startX + 1 && startY < endY ; i--) {
            ret.push_back(matrix[i][startY]);
        }

    }
};

