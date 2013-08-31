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
            Node node ; node.v = numbers[i];node.pos = i ;
            nodes.push_back(node);
        }
        sort(nodes.begin(),nodes.end());
        vector<int> ret(2);
        for(int i = 0 ; i< nodes.size(); i++){
            ret[0] = nodes[i].pos+1;
            int n = nodes[i].v;
            int t = target - n ;
            int p = find(nodes,t,0,nodes.size());
            if(p != -1 ) {
                ret[1] = nodes[p].pos+1;
                if(ret[0] > ret[1] ) swap(ret[0],ret[1]);
                return ret;
            }
        }
    }
    int find(vector<Node> & nums , int n,int s,int e){
        if(s >= e ){
            return -1;
        }
        int m = (s+e)/2;
        if( n < nums[m].v ){
            return find(nums,n,s,m);
        }else if(n> nums[m].v ){
            return find(nums,n,m+1,e); 
        }else{
            return m;
        }
    }
};


