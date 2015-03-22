/**
 * O(n) 记录左边第一个未匹配括号的位置 即可
 * Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

 For "(()", the longest valid parentheses substring is "()", which has length = 2.

 Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
 */
struct Node{
    char c ;
    int index;
    Node(){}
    Node(char c,int index):c(c),index(index){}
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

