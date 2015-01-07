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

// java version 
public class Solution {
    /**
     * @param nums: A list of integers
     * @return: A list of integers that's next permuation
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
    public ArrayList<Integer> nextPermuation(ArrayList<Integer> nums) {
		
        if(nums == null || nums.size() == 0 ) return nums; 
      
      
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
            if(i > 0 ) {
                
                swap( nums, i )  ;
            }
            reverse(nums , i ) ; 
            return nums; 
         
    }
}

// Previous permutation ...almost the same as above one .
public class Solution {
    /**
     * @param nums: A list of integers
     * @return: A list of integers that's previous permuation
     */
    public ArrayList<Integer> previousPermuation(ArrayList<Integer> nums) {
		// write your code
		if(nums == null || nums.size() == 0 ) return nums; 
        int i = nums.size() - 1 ; 
        int cur = 0 , prev = 0 ; 
        while(i>=1){
            cur = nums.get(i) ; 
            prev = nums.get(i-1)  ; 
            if(prev <= cur) { // change point 1 
                i-- ; 
            }else{
                break ; 
            }
        }
        swap( nums, i )  ;
        reverse(nums , i ) ; 
        return nums; 

    }
    public void swap(ArrayList<Integer> nums , int i ) {
        if(i == 0 ) return  ;
        for(int j = nums.size() - 1 ; j >= i  ; j-- ) {
            if(nums.get(j) < nums.get(i-1) ) { // change point 2
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

}



