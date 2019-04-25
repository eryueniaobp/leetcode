# encoding=utf-8
import  copy
class Solution:

    def solve(self, board, b2, idx, row, col, mat):

        i =  idx//9
        j = idx% 9
        if i > 8 : return True
        if board[i][j] == '.':
            # find all the valid state
            k = i // 3 * 3 + j // 3
            for num in range(1, 10): # 1 -> 9

                if row[i][num-1] == 0  and col[j][num-1] == 0 and mat[k][num-1] == 0:
                    row[i][num-1] = 1
                    col[j][num-1] = 1
                    mat[k][num-1] = 1

                    board[i][j] = str(num)
                    if not self.solve(board, b2,  idx +1 , row,col, mat):
                        row[i][num-1] = 0
                        col[j][num-1] = 0
                        mat[k][num-1] = 0
                        board[i][j] = '.'
                    else:
                        return True
            return False



        else:
            return self.solve(board, b2, idx+1 , row, col, mat)

    def solveSudoku(self, board) -> None:
        """
        Do not return anything, modify board in-place instead.
        board
        """
        b2 = copy.deepcopy(board)

        row = [[0] * 9 for i in range(9)]
        col = [[0] * 9 for i in range(9)]
        mat = [[0] * 9 for i in range(9)]

        for i in range(9):
            for j in range(9):
                if board[i][j] != '.':
                    idx = int(board[i][j]) - 1
                    row[i][idx] = 1
                    col[j][idx] = 1
                    k = i // 3 * 3 + j // 3
                    mat[k][idx] = 1

        # find all the valid state
        idx = 0
        self.solve( board, b2, 0 , row, col , mat  )


sol = Solution()
board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]

sol.solveSudoku(board)

print(board)








