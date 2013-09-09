/**
 * 验证 每行 每列 每个小的九宫格
 */
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return 
            isValidRow(board) && isValidColumn(board) && isValidBox(board);
    }

private:    
    bool isValidRow(vector<vector<char> > &board) {
        int count[9];        
        for (int i = 0; i < 9; i++) {
            memset(count, 0, sizeof(int) * 9);
            for (int j = 0; j < 9; j++) {
                if (!add(count, board[i][j])) {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isValidColumn(vector<vector<char> > &board) {
        int count[9];        
        for (int i = 0; i < 9; i++) {
            memset(count, 0, sizeof(int) * 9);
            for (int j = 0; j < 9; j++) {
                if (!add(count, board[j][i])) {
                    return false;
                }
            }
        }
        return true;    
    }
    
    bool isValidBox(vector<vector<char> > &board) {
        int point[9][2] = {
    		{1, 1}, {1, 4}, {1, 7}, {4, 1}, {4, 4}, {4, 7}, {7, 1}, {7, 4}, {7, 7}
    	};
    	int dir[8][2] = {
        	{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}
    	};    	
        int count[10];
        
        for (int i = 0, x, y; i < 9; i++) {
            memset(count, 0, sizeof(int) * 10);                            
            x = point[i][0];
            y = point[i][1];
            add(count, board[x][y]);                
            for (int j = 0; j < 8; j++) {
                if (!add(count, board[dir[j][0] + x][dir[j][1] + y])) {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool add(int count[], char c) {
        if (c == '.') {
            return true;
        }
        return (++count[c - '1']) <= 1;
    }
};

