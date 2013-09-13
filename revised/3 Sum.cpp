/**
 *  O(nlogn) + O(n^2)
 * */
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size = num.size();
        vector<vector<int> > ret;
        if(size == 0 ) {
            return  ret;
        }
        sort(num.begin(),num.end());
      
        vector<int> vset(3);
        for(int i = 0 ;num[i]<=0 && i<size; i ++ ){
            if( i> 0 && num[i] == num[i-1] ) continue;
            int target = 0 - num[i] ; 
            int j = i + 1 , k = size -1; 
            while ( j < k  && num[j] <= target) {
                int sum = num[j] + num[k] ; 
                if(sum < target ) {
                    j++;
                }else if(sum >  target) {
                    k -- ; 
                }else{
                    vset[0] = num[i] ;
                    vset[1] = num[j] ; 
                    vset[2] = num[k] ;
                    ret.push_back(vset);
                    while(j+1<size && num[j+1] == num[j] ) j++ ; 
                    j++ ; 
                    while(k-1 >=0 && num[k] == num[k-1] ) k -- ;
                    k--;
                }
            }
        }
        return ret;
    }
};

