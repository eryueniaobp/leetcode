class Solution {
    public int countRangeSum(int[] nums, int lower, int upper) {
    
        // use TreeMap also can solve the problem. TreeMap.subMap is magic. but the merge sort is more practical in onsite review.
        if (nums == null || nums.length == 0) return 0;
        long[] sums = new long[nums.length];
        sums[0] = nums[0];
        for (int i = 1; i < sums.length; i++)
            sums[i] = sums[i-1] + nums[i];
        return divide(sums, 0, sums.length - 1, lower, upper);
    }
    private int divide(long[] sums, int lo, int hi, int lower, int upper) {
        if (lo >= hi) return sums[lo] >= lower && sums[lo] <= upper ? 1 : 0;
        int mid = (lo + hi) >> 1;
        int res = divide(sums, lo, mid, lower, upper) + divide(sums, mid + 1, hi, lower, upper);
        int i = mid + 1, j = mid + 1;
        for (int k = lo; k <= mid; k++) {
            while (i <= hi && sums[i] - sums[k] < lower) i++;
            while (j <= hi && sums[j] - sums[k] <= upper) j++;
            res += j - i;
        }
        merge(sums, lo, hi, mid);
        return res;
    }
    private void merge(long[] sums, int lo, int hi, int mid) {
        long[] tmp = new long[hi-lo+1];
        System.arraycopy(sums, lo, tmp, 0, hi - lo + 1);
        int i = lo, j = mid + 1, idx = 0;
        while (i <= mid && j <= hi) {
            if (sums[i] < sums[j]) tmp[idx++] = sums[i++];
            else tmp[idx++] = sums[j++];
        }
        while (i <= mid) tmp[idx++] = sums[i++];
        while (j <= hi) tmp[idx++] = sums[j++];
        System.arraycopy(tmp, 0, sums, lo, hi - lo + 1);
}
}
