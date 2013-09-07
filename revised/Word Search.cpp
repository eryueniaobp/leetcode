/**
 * DFS 
 */
struct Node{
    int x;
    int y;
    Node():x(-1),y(-1){};
    Node(int x,int y):x(x),y(y){}
};
class Solution {
    vector<Node> nodes_;  
    int tag_[100][100];
public:
    bool canUse(vector<vector<char> > &board,int line,int col){
        return  line < board.size() && line >= 0 && col<board[0].size() && col >=0 && tag_[line][col] != 1 ;
    }
    bool seek(vector<vector<char> > &board, string &word,int line,int col,int level){
        if(level >= word.size() ) {
            return true;
        }
        if( !canUse(board,line,col) ) {
            return false;
        }
        if(board[line][col] == word[level] ) {
            tag_[line][col] = 1;
            for(int i = 0 ; i < 4 ; i++){
                if(seek(board,word,line+nodes_[i].x,col+nodes_[i].y,level+1)){
                    return true;
                }
            }
            tag_[line][col] = 0;
            return false; 
        }
        return false;
    }
    
    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() functionze
        nodes_.resize(4);
        nodes_[0] = Node(0,1);
        nodes_[1] = Node(1,0);
        nodes_[2] = Node(0,-1);
        nodes_[3] = Node(-1,0);
        memset(tag_,0,100*100*sizeof(int));
        char ch = word[0];
        for( int l = 0; l < board.size() ; l ++ ) {
            for( int c = 0; c < board[0].size() ; c ++ ){
                if(board[l][c] == ch && seek(board,word,l,c,0) )  {
                     return true;
                }
            }
        }
        
        return false;
    }
};

