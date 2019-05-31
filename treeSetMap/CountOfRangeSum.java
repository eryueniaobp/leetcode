class Solution {
    public int countRangeSum(int[] nums, int lower, int upper) {
        if(nums.length == 0) return 0 ;
        long [] sums = new long[nums.length];
        sums[0] = nums[0];

        for ( int i = 1 ; i < nums.length ; i++ ){
            sums[i] = sums[i-1] + nums[i];

        }

        TreeMap<Long,Integer> ts=  new TreeMap<>();
        // ts.add(L);
        ts.put(sums[0], 1 );
        int ret = 0 ;
        if(sums[0] <=upper && sums[0] >=lower) ret += 1;

        for(int i = 1 ; i< nums.length ; i++){
            long cur = sums[i];
            long prevlower = cur - upper ;
            long prevupper = cur -  lower ;  // (i,  j]

            Map<Long,Integer> sub = ts.subMap(prevlower, true, prevupper, true);
            for(int c : sub.values()) ret += c;
            if ( cur >= lower && cur <= upper) ret += 1 ;
            ts.put(cur, 1 + ts.getOrDefault(cur, 0 ));

        }
        // if(nums.length > 1 && sums[nums.length-1] >=lower && sums[nums.length -1] <= upper ) ret += 1 ;
        return ret ;

    }

}
