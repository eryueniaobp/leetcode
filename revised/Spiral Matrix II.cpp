/**
 * O(n*n) 
 * 每次都填满四周的边界
 */
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
          int startX = 0;
        int startY = 0;
        int endX = n - 1;
        int endY = n - 1;
        
        vector<vector<int> > matrix ( n,vector<int>(n)) ;
        int startValue = 1;
        
        while (startX <= endX) {
            startValue = fillNumber(startX, startY, endX, endY, matrix, startValue);
            startX++;
            startY++;
            endX--;
            endY--;
        }
        return matrix; 
    }
    int fillNumber(int startX, int startY, int endX, int endY, vector<vector<int>> &matrix, int startV) {
        if (startX == endX) {
            matrix[startX][startY] = startV;
            return -1;
        }
        
        for (int i = startY; i <= endY; i++) {
            matrix[startX][i] = startV;
            startV++;
        }
        for (int i = startX + 1; i <= endX; i++) {
            matrix[i][endY] = startV;
            startV++;
        }
        
        for (int i = endY - 1; i >= startY; i--) {
             matrix[endX][i] = startV;
            startV++;
        }
        
        for (int i = endX - 1; i >= startX + 1; i--) {
             matrix[i][startY] = startV;
             startV++;
        }
        
        return startV;
    }
};
