//http://lintcode.com/zh-cn/problem/minimum-adjustment-cost/
//http://www.cnblogs.com/yuzhangcmu/p/4153927.html#commentform
public class Solution {
    /**
     * @param A: An integer array.
     * @param target: An integer.
     */
    public int MinAdjustmentCost(ArrayList<Integer> A, int target) {
        // write your code here
        // write your code here
        if (A == null || A.size() == 0) {
            return 0;
        }
        
        // D[i][v]: 把index = i的值修改为v，所需要的最小花费
        int[][] D = new int[A.size()][101];
        
        int size = A.size();
        
        for (int i = 0; i < size; i++) {
            for (int j = 1; j <= 100; j++) {
                D[i][j] = Integer.MAX_VALUE;
                if (i == 0) {
                    // The first element.
                    D[i][j] = Math.abs(j - A.get(i));
                } else {
                    for (int k = 1; k <= 100; k++) {
                        // 不符合条件 
                        if (Math.abs(j - k) > target) {
                            continue;
                        }
                        
                        int dif = Math.abs(j - A.get(i)) + D[i - 1][k];
                        D[i][j] = Math.min(D[i][j], dif);
                    }
                }
            }
        }
        
        int ret = Integer.MAX_VALUE;
        for (int i = 1; i <= 100; i++) {
            ret = Math.min(ret, D[size - 1][i]);
        }
        
        return ret;
    }
}

