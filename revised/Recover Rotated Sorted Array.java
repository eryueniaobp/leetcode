// http://lintcode.com/zh-cn/problem/recover-rotated-sorted-array/  
// Given a rotated sorted array, recover it to sorted array in-place 
public class Solution {
    /**
     * @param nums: The rotated sorted array
     * @return: The recovered sorted array
     */
    public void recoverRotatedSortedArray(ArrayList<Integer> nums) {
        // write your code
        int l = nums.size();
        for (int i = 1; i < l; i++) {
            if (nums.get(i) < nums.get(i - 1)) {
                reverse(nums, 0, i - 1);
                reverse(nums, i, l - 1);
                reverse(nums, 0, l - 1);
                break;
            }
        }
    }
    public void reverse(ArrayList<Integer> nums, int start, int end) {
        int temp;
        while (start < end) {
            temp = nums.get(start);
            nums.set(start, nums.get(end));
            nums.set(end, temp);
            start++;
            end--;
        }
    }
}

