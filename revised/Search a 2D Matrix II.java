import java.util.* ;
/**
http://lintcode.com/zh-cn/problem/search-a-2d-matrix-ii/ 
Search a 2D Matrix II  

Write an efficient algorithm that searches for a value in an m x n matrix, return the occurrence of it.

This matrix has the following properties:

    * Integers in each row are sorted from left to right.

    * Integers in each column are sorted from up to bottom.

    * No duplicate integers in each row or column.

样例
Consider the following matrix:

[

    [1, 3, 5, 7],

    [2, 4, 7, 8],

    [3, 5, 9, 10]

]

Given target = 3, return 2. 
Challenge: 
    O(m+n) time and O(1) extra space 
*/
// Not so good solution . 
public class Solution {
    /**
     * @param matrix: A list of lists of integers
     * @param: A number you want to search in the matrix
     * @return: An integer indicate the occurrence of target in the given matrix
     */
    public int searchMatrix(ArrayList<ArrayList<Integer>> matrix, int target) {
        int cnt =  0 ; 
        for(ArrayList<Integer> row : matrix ) { 
            cnt +=  Collections.binarySearch(row , target) < 0 ? 0 : 1 ; 
        }
        return cnt  ;
    }
    public static void main(String []args) {
        List<Integer> a = new ArrayList<Integer>() ;
        a.add(1)  ;
        a.add(3) ;
        System.out.println( Collections.binarySearch(a , 0 ));
    }
}

// An expected solution 
import java.util.* ;
public class Solution {
    /**
     * @param matrix: A list of lists of integers
     * @param: A number you want to search in the matrix
     * @return: An integer indicate the occurrence of target in the given matrix
     */
    public int searchMatrix(ArrayList<ArrayList<Integer>> matrix, int target) {
        if(matrix.size() == 0 || matrix.get(0).size() == 0 ) return 0 ;
        int cnt =  0 ;
        int r =  0 ;
        int c  = matrix.get(0).size()  -1 ;

        while(c>=0 && r < matrix.size() ) {
            int cur = get(r,c, matrix) ;
            if(target < cur) {
                c-- ;
            }else if(target > cur)  {
                r ++ ;
            }else{
                cnt ++ ;
                if(c>0) c-- ;
                else{
                    r++ ; 
                }
            }
        }
        return cnt  ;
    }
    public int get ( int r, int c , ArrayList<ArrayList<Integer>> matrix) {
        if( r < matrix.size()  && c < matrix.get(0).size() ) {
            return matrix.get(r).get(c) ;
        }
        throw new ArrayIndexOutOfBoundsException() ;
    }
}
