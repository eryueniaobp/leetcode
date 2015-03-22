/*
* quick-select algorithm: O(N) 
* N ( 1 + 1/2 + 1/4 + 1/8 )  = N *2  .. 
* Note: 1th largest number is the max number . not the the min number
* Reference: Median of two sorted array 
*/
class Solution {
    //param k : description of k
    //param numbers : array of numbers
    //return: description of return
    public int kthLargestElement(int k, ArrayList<Integer> numbers) {
        // if( k > numbers.size() ) k = numbers.size() ; // 
        k = numbers.size() - k + 1 ;
        int L = 0 , R = numbers.size() - 1 ; 
        while(true) {
            
            int i = L  , j = R ;
            int pivot = numbers.get(L) ; 
            while( i < j ) {
                while( i <=j && numbers.get(i) <= pivot ) i++  ;
                while( j >=i && numbers.get(j) >pivot) j -- ;  
                
                if( i < j ) {
                    Collections.swap(numbers, i , j ) ; 
                }
            }
            Collections.swap(numbers, L , j  ) ; 
            i = j + 1  ; 
            if( i - L == k ) {
                return pivot;
            }else if( i - L < k ) {
                k = k - ( i - L ) ; 
                L = i  ; 
            }else {
                R = i - 1 ; 
            }
        }
    }
};

