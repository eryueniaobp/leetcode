/**
 *  O(nlogn) + O(n^2)
 * */
class Solution {
public:
    
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size = num.size();
        if(size == 0 ) {
            return  0;
        }
        sort(num.begin(),num.end());
        int diff = INT_MAX; 
        int ret = INT_MAX;
        for(int i = 0 ; i<size; i ++ ){
            int curt = target - num[i] ; 
            int j = i + 1 , k = size -1; 
            while ( j < k ) {
                int sum = num[j] + num[k] ; 
                if( abs(curt - sum ) < diff ) {
                    diff = abs(curt-sum) ;
                    ret = target - (  curt - sum )  ;
                }
                if(sum < curt ) {
                    j++;
                }else if(sum >  curt ) {
                    k -- ; 
                }else{
                    return target ; 
                }
            }
        }
        return ret;
    }
};

