/**
 * O(n) 经典算法
 */
class Solution {
public:
    void reverse(vector<int> & num , int l ,int r) {
        for(int i = 0 ; i < (r - l)/2 ; i ++ ) {
            swap(num[l+i] , num[r-1 -i]);
        }
    }
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function        
        int i = num.size() - 2;
        while (i >= 0 && num[i] >= num[i + 1]) {
            i--;
        }
        if (i < 0) {
            reverse(num,0,num.size());
        }else {
            int j = i + 2;
            while (j < num.size() && num[j] > num[i]) {
                j++;
            }
            j--;
            swap(num[i],num[j]); 
            reverse(num,  i + 1, num.size());
        }
    }
};

