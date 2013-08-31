struct Node{
    int val;
    int left;
    int right;
    Node(int v,int l,int r):val(v),left(l),right(r) {}
};
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int s = height.size();
        if(s == 0) return 0;
        vector<Node> hnodes;
        for(int i = 0 ; i< height.size() ; i ++ ) {
            hnodes.push_back(Node(height[i],i,i)); 
        }
        for(int i = 0 ; i < hnodes.size() ; i++ ) {
            while(hnodes[i].left > 0 && hnodes[i].val <= hnodes[ hnodes[i].left - 1 ].val ) {
                hnodes[i].left = hnodes [ hnodes[i].left - 1  ].left ;
            }
        }
        for(int i = s -1 ; i >= 0 ; i--){
            while(hnodes[i].right < s-1 && hnodes[i].val <= hnodes[ hnodes[i].right + 1].val ){
                hnodes[i].right = hnodes[ hnodes[i].right +1 ].right ;
            }
        }
        int max = INT_MIN ; 
        int tmp  ;
        for(int i = 0 ; i< hnodes.size() ; i ++ ){
            tmp = hnodes[i].val * ( hnods[i].right - hnodes[i].left +1 ) ;
            if(tmp > max) {
                max =tmp ;
            }
        }
        return max;
    }
};

