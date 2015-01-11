// Design an algorithm to find the kth number such that the only prime factors are 3, 5, and 7. 
class Solution {
    /**
     * @param k: The number k.
     * @return: The kth prime number as description.
     */
    public long kthPrimeNumber(int k) {
        if (k==0) return 1;
        
        long[] res = new long[k+1];
        res[0] = 1;
        int p3 = 0, p5 = 0, p7 = 0;
        for (int i=1;i<=k;i++){
            //find the minimum prime number.
            long val = Math.min(res[p3]*3, res[p5]*5);
            val = Math.min(val, res[p7]*7);
            if (val / res[p3] == 3) p3++;
            if (val / res[p5] == 5) p5++;
            if (val / res[p7] == 7) p7++;
            res[i] = val;
        }
        return res[k];
    }
};
