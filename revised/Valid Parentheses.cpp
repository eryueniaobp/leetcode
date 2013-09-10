/**
 * O(n)的算法
 */
class Solution {
public:
    bool isRight(char a ){
        return a=='}' || a== ']' || a == ')' ;
    }
    char left(char a){
        if(a == '}'){
            return '{';
        }
        if( a== ']' ){
            return '[';
        }
        if( a== ')'){
            return '(';
        }
    }
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<char> cstak;
        int i = 0 ; 
        int size = s.size();
        while(i<size){
            if(isRight(s[i])){
                char a = left(s[i]);
                if(!cstak.empty() && cstak.top() == a ){
                    cstak.pop();
                }else{
                    return false;
                }
            }else{
                cstak.push(s[i]);
            }
            i++;
        }
        return cstak.size() == 0;
    }
};

