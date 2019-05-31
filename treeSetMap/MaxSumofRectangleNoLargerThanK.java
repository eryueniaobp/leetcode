class Solution {
    public int maxSumSubmatrix(int[][] matrix, int k) {
        // <= k 
        int m = matrix.length;
        int n = matrix[0].length;
        int[][] sums = new int[m][n];

        /**
         * 按照列来求和
         */
        for(int col = 0 ; col < n; col ++){
            for(int row = 0 ; row < m ; row ++){
                if(row == 0)
                    sums[row][col] = matrix[row][col];
                else
                    sums[row][col] = sums[row - 1][col] + matrix[row][col];
            }
        }
        
        int result = Integer.MIN_VALUE ;
        
        for(int col1 = 0 ; col1 < n ; col1 ++){
            for(int col2 = col1; col2 < n ; col2++){
                TreeSet<Integer> set = new TreeSet<>();
                set.add(0);
                for(int row = 0 ; row < m ; row++){
                    int sum = 0 ;
                    for(int i = col1; i <= col2; i++){
                        sum += sums[row][i];
                    }
                    if(set.ceiling(sum-k) != null){
                        int max = sum  - set.ceiling(sum - k); 
                        result = Math.max(result, max); 
                    }
                    set.add(sum); 
                    
                }
                
            }
        }
        return result ;
        
        
        
        
    }
}
