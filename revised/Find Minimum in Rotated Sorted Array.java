/**
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
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
        while(s <=e ){
            int mid = s + (e-s)/2 ; 
            if(nums[s] <= nums[mid] && nums[e] < nums[mid] ) { // point : <= ,not just < 
                s = mid + 1; 
            }else if(nums[s] > nums[mid] && nums[e] > nums[mid] ) {
                e = mid ; 
            }else{
                e = mid  ; 
                if( s == e) {
                    break; 
                }
            }
        }
        return nums[e]  ;
    }
}

