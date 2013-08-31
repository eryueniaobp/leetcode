struct Node{
    int val;
    int pos;
    Node(int v,int p):val(v),pos(p) {}
};
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int s = height.size();
        if(s == 0) return 0;
        int max = INT_MIN;
        stack<Node> nStack;
        nStack.push(Node(INT_MIN,-1));
        for(int i = 0 ; i<height.size() ; i++){
            while(!nStack.empty()){
                Node node = nStack.top();
                if(node.val <= height[i] ){
                    nStack.push(Node(height[i],i));
                    break;
                }else{
					nStack.pop();
                    int len = i - nStack.top().pos -1;
                    if(nStack.size() == 1 ){
                        len = i ;
                    }
                    
                    int cur =(len) * node.val;
                    if(cur > max){
                        max = cur;
                    }
                }
            }
        }
        while(nStack.size() > 1 ){
			Node node = nStack.top();
			nStack.pop();
            int len =  height.size() - nStack.top().pos -1 ;
            if(nStack.size() == 1 ){
                len = height.size() ;
            }
            int cur = (  len ) * node.val ;
            if(cur > max){
                max = cur;
            }
        }
        return max;
    }
};

