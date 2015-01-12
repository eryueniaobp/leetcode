/**
Given board =

[
  "ABCE",
  "SFCS",
  "ADEE"
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false. 

A more decent solution. 
**/
public class Solution {
    /**
     * @param board: A list of lists of character
     * @param word: A string
     * @return: A boolean
     */
    boolean [][]visited = null; 
    public boolean exist(char[][] board, String sword) {
        char []word = sword.toCharArray() ; 
        visited = new boolean[board.length][board[0].length] ; 
        
        for(int i = 0 ; i < board.length  ; i++ ) {
            for(int j = 0 ; j< board[0].length ; j++ ){
                if(seek(board, i , j , word , 0 ) ) {
                    return true; 
                }
            }
        }
        return false ; 
    }
    protected boolean seek(char [][]board , int i , int j , char []word , int k ) {
        if( k == word.length ) return true ; 
        if( i<0 || j< 0 || i>=board.length || j >= board[0].length || visited[i][j] || board[i][j] != word[k] ) return false ;
        visited[i][j] = true ; 
        // up
        boolean ok = seek(board, i-1, j ,word, k+1) ||seek(board, i+1 , j ,word, k+1 ) 
                        || seek(board, i ,j-1 , word, k+1 ) || seek(board, i ,j+1,word,k+1) ; 
        
        visited[i][j] = false ;
        
        return ok ;
        
        
    }
}

