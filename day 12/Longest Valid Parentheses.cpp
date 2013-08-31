struct Node{
    char c ;
    int index;
    Node(){

    }
    Node(char _c,int _index):c(_c),index(_index){

    }
};
class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<Node> cst;
        int i = 0 ; 
        int max = 0;
        int cur = 0 ,left = -1;
        cst.push(Node(')',-1));
        while( i <s.size()){
            char a = s[i];
            if(a == ')' ){
                if(!cst.empty() && cst.top().c == '(' ){
                    cst.pop();
                    cur = i - cst.top().index;
                }else{
                    cur = 0 ;
                    cst.push(Node(')',i));
                   // while(!cst.empty()) cst.pop();
                }
            }else{
                cst.push(Node('(',i));
            }
            if(cur > max) max = cur;
            i++;
        }
        return max;
    };
};

