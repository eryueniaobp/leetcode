struct Node{
    int x;
    int y;
    Node():x(-1),y(-1){};
    Node(int _x,int _y):x(_x),y(_y){}
   /* int compare(const Node& node ) const {
    	if(x == node.x && y == node.y ) {
			return 0 ;
		}else{
			return 1;
		}
	}
	bool operator == (const Node& node) const {
		return x == node.x && y == node.y ;
	}*/
	
    
};
class Solution {
    vector<Node> _nodes;  
    set<pair<int,int> > _tag;
public:
    bool canUse(vector<vector<char> > &board,int line,int col){
        return  line < board.size() && line >= 0 && col<board[0].size() && col >=0 && _tag.find(pair<int,int>(line,col)) == _tag.end() ;
    }
    bool seek(vector<vector<char> > &board, string &word,int line,int col,int level){
        if(level >= word.size() ) {
            return true;
        }
        if( !canUse(board,line,col) ) {
            return false;
        }
        if(board[line][col] == word[level] ) {
            _tag.insert(pair<int,int>(line,col));
            for(int i = 0 ; i < 4 ; i++){
                if(seek(board,word,line+_nodes[i].x,col+_nodes[i].y,level+1)){
                    return true;
                }
            }
            _tag.erase(pair<int,int>(line,col));
            return false; 
        }
        return false;
    }
    
    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() functionze
        _nodes.resize(4);
        _nodes[0] = Node(0,1);
        _nodes[1] = Node(1,0);
        _nodes[2] = Node(0,-1);
        _nodes[3] = Node(-1,0);
        _tag.clear();
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

