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


/** python python is more elegant **/
class Solution:
    """
    @param numbers : An array of Integer
    @param target : target = numbers[index1] + numbers[index2]
    @return : [index1 + 1, index2 + 1] (index1 < index2)
    """
    def twoSum(self, numbers, target):
        # write your code here
        numbers = [ (j, i) for i , j  in enumerate(numbers) ]
        numbers = sorted(numbers , key=lambda x:x[0]) 
        i = 0 
        j = len(numbers) - 1
        while i < j : 
            sum = numbers[i][0] + numbers[j][0] 
            if sum > target: 
                j-=1 
            elif sum<target:
                i+=1
            else:
                return sorted([numbers[i][1]+1, numbers[j][1]+1]) 
                    
