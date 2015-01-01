/**
 * dfs 
 */
class Solution {
    vector<vector<int> > ret_;
    vector<int> perm_;
    unordered_set<int> set_;
public:
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret_.clear();
        dfs(num,0);  
        return ret_;
    }
    void dfs(vector<int> &num ,int l){
        if( l == num.size() ) {
            ret_.push_back(perm_);
            return;
        }
        for(int i = 0 ;i<num.size(); i ++){
            if(set_.find(num[i]) != set_.end()) {
                continue;
            }
            perm_.push_back(num[i]);
            set_.insert(num[i]);
            dfs(num,l+1);
            set_.erase(num[i]);
            perm_.pop_back();
        }
    }
};

/** non-recursive and it will return unique permutations . **/ 
class Solution {
    /**
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    public void swap(ArrayList<Integer> nums , int i ) {
        for(int j = nums.size() - 1 ; j >= i  ; j-- ) {
            if(nums.get(j) > nums.get(i-1) ) {
                Collections.swap(nums,i-1 , j) ;
                break; 
            }
        }
        
    }
    public void reverse(ArrayList<Integer> nums , int i ) { 
        int j =  i , k = nums.size() -1  ;
        while( j < k ) {
            Collections.swap(nums,j,k) ; 
            j++ ; 
            k--; 
        }
    }
    
    public ArrayList<ArrayList<Integer>> permute(ArrayList<Integer> nums) {
        ArrayList<ArrayList<Integer>> ps = new ArrayList<ArrayList<Integer>>() ; 
        if(nums == null || nums.size() == 0 ) return ps; 
        Collections.sort(nums) ; 
        
        ArrayList<Integer> perm = new ArrayList<Integer>() ;
        perm.addAll(nums) ; 
        ps.add(perm) ;
        while(true){
            int i = nums.size() - 1 ; 
            int cur = 0 , prev = 0 ; 
            while(i>=1){
                cur = nums.get(i) ; 
                prev = nums.get(i-1)  ; 
                if(prev >= cur) {
                    i-- ; 
                }else{
                    break ; 
                }
            }
            if(i == 0 )  break;  
            swap( nums, i )  ;
            reverse(nums , i ) ; 
            perm = new ArrayList<Integer>() ; 
            perm.addAll(nums) ; 
            ps.add(perm) ; 
            
        }
        return ps ; 
        
    }
}



