/**
 * O(nlogn) +　O(n)
 */
struct Node{
    int v;
    int pos;
    bool operator< (const Node&a) const {
        return v < a.v ;
    }
};
class Solution {
    
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<Node> nodes;
        for(int i = 0 ;i<numbers.size() ;i ++ ){
            Node node ; node.v = numbers[i];node.pos = i+1 ;
            nodes.push_back(node);
        }
        sort(nodes.begin(),nodes.end());
        vector<int> ret(2);
        int i = 0 , j = nodes.size() -1; 
        while( i < j ) {
            int sum = nodes[i].v + nodes[j].v  ; 
            if(sum > target){
                j -- ; 
            }else if(sum < target){
                i ++ ; 
            }else{
                ret[0] = nodes[i].pos ;
                ret[1] = nodes[j].pos;
                if(ret[0] > ret[1]) swap(ret[0],ret[1]);
                return ret;
            }
        }
    }
};



