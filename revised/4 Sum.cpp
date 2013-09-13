/**
 * O(nlogn) + O(n^3) 
 */
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<vector<int> > ret;
        int size= num.size();
        if(size == 0 ) {
            return ret;
        }
        sort(num.begin(), num.end());
        vector<int> vset(4);
        for(int i = 0; i < num.size(); i++) {
            if (i > 0 && num[i] == num[i-1])
                continue;
                
            for(int j = i + 1; j < num.size(); j++) {
                if (j > i + 1 && num[j] == num[j-1])
                    continue;
                    
                int k = j + 1;
                int t = num.size() - 1;
                
                while(k < t) {
                    int sum = num[i] + num[j] + num[k] + num[t];
                    if (sum == target) {
                        vset[0] =  num[i];
                        vset[1] = num[j];
                        vset[2]  = num[k];
                        vset[3] = num[t];
                        ret.push_back(vset);
                        while( k+1 < size && num[k] == num[k+1] ) k ++ ;
                        k++ ; 
                        while( t-1 >=0 && num[t] == num [t-1] ) t--;
                        t-- ;
                    }
                    else if (sum < target)
                        k++;
                    else
                        t--;                        
                }
            }
        }
        
        return ret;
    }
};

