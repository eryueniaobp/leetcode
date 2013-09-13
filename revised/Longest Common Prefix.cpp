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

