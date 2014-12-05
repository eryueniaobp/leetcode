/**
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

样例
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
 * 
 */

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return an integer
     */
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> nset ; 
        for(int i = 0 ; i< num.size() ; i++ ) nset.insert(num[i]) ; 
        
        
        int maxlen = 0 ; 
        for(int i = 0 ; i< num.size() ; i ++ ){
            if(nset.find(num[i]) != nset.end()) {
                int cur = 1  ; 
                int j = num[i] + 1 ; 
                while(nset.find(j) != nset.end() ) {
                    nset.erase(j) ; 
                    j++ ; 
                    cur ++ ;  
                    
                }
                j = num[i] -1 ; 
                while(nset.find(j) != nset.end()) {
                    nset.erase(j) ;  
                    j -- ; 
                    cur++ ; 
                    
                }
                
                if(cur > maxlen) maxlen = cur; 
            }
        }
        return maxlen; 
    }
};

