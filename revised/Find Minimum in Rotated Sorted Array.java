/**
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume *no duplicate* exists in the array.
*/
public class Solution {
    /**
     * @param num: a rotated sorted array
     * @return: the minimum number in the array
     */
    public int findMin(int[] nums) {
        if(nums.length == 1 ) {
            return nums[0] ; 
        }
        int s = 0 , e = nums.length - 1; 
        while(s < e ){
            int mid = s + (e-s)/2 ; 
            if(nums[s] <= nums[mid] && nums[e] < nums[mid] ) { // point : <= ,not just < 
                s = mid + 1; 
            }else if(nums[s] > nums[mid] && nums[e] > nums[mid] ) {
                e = mid ; 
            }else{
                e = mid  ; 
           }
        }
        return nums[e]  ; // nums[s] will also be ok .
    }
}

// Another Problem : there are duplicates in the array .
// Note : the solution below is not perfect though it can pass the testcases of lintcode.
public class Solution {
    /**
     * @param num: a rotated sorted array
     * @return: the minimum number in the array
     */
    public int findMin(int[] nums) {
        if(nums.length == 1 ) {
            return nums[0] ; 
        }
        int s = 0 , e = nums.length - 1; 
        while(s < e ){
            int mid = s + (e-s)/2 ; 
            if(nums[s] <= nums[mid] ) {
                if(nums[e] < nums[mid] ) {
                    s = mid + 1; 
                }else if(nums[e] == nums[mid]) {
                    while(e > s && nums[e] == nums[mid]) e-- ; 
                    if(e==s) {
                        break; 
                    }
                    
                    if(nums[e] > nums[mid] ) {
                        return nums[mid] ; 
                    }else { // < 
                        s = mid + 1  ; 
                    }
                }
            }else {
                e = mid; 
            }
        }
        return nums[e]  ;
    }
}


