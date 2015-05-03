/**
 * O(k* length(prefix)) k = strs.size() 
 */
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size = strs.size();
        if(size == 0 ) return "";
        string prefix = strs[0];
        int min = prefix.size();
        for(int i = 1 ;i < size ; i++){
            string node = strs[i];
            int j = 0 ; 
            while( j< node.size() && j< prefix.size() && j<min && node[j] == prefix[j]){
                j++;
            }
            if(j < min){
                min = j ; 
            }
        }
        return prefix.substr(0,min);
    }
};

/** python **/
class Solution:
    # @param strs: A list of strings
    # @return: The longest common prefix
    def longestCommonPrefix(self, strs):
        # write your code here
        if strs == None or len(strs) == 0 :
            return ""
        p = 10000000
        t = strs[0]
        for s in strs:
            i = 0 
            while i < len(s) and i<len(t): 
                if s[i] != t[i]:
                    break
                i+=1
            p = min(p,i)
        return t[:p]

