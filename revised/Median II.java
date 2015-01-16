/**
Numbers keep coming, return the median of numbers at every time a new number added  
*/
import java.util.* ;
public class Solution {
    /**
     * @param nums: A list of integers.
     * @return: the median of numbers
     */
    public int[] medianII(int[] nums) {
        Queue<Integer> lmaxHeap = new PriorityQueue<Integer>(nums.length , new Comparator<Integer>(){
            public int compare(Integer a , Integer b) {
                return b - a;
            }
        }) ;
        Queue<Integer> rminHeap = new PriorityQueue<Integer>(nums.length, new Comparator<Integer>() {
            @Override
            public int compare(Integer integer, Integer t1) {
                return integer - t1 ;
            }
        }) ;
        int i = 0 ;
        int []median = new int[nums.length] ;
        while( i < nums.length ) {
            int n = nums[i] ;
            if(lmaxHeap.isEmpty() && rminHeap.isEmpty()) {
                lmaxHeap.offer(n) ;
            }else if(lmaxHeap.isEmpty()) {
                if( n < rminHeap.peek() )
                    lmaxHeap.offer(n) ;
                else{
                    rminHeap.offer(n) ;

                }
            }else if(rminHeap.isEmpty()) {
                if( n > lmaxHeap.peek() )
                    rminHeap.offer(n) ;
                else{
                    lmaxHeap.offer(n) ;
                }
            }else{
                int l =lmaxHeap.peek() ;
                int r =rminHeap.peek() ;

                if( l<=n && n<=r ) {
                   lmaxHeap.offer(n) ;
                }else if( n<=l ) {
                    lmaxHeap.offer(n) ;
                }else if( r<=n ) {
                    rminHeap.offer(n) ;
                }

            }
            adjust ( lmaxHeap, rminHeap ) ;
            // System.out.println(lmaxHeap.size() + "\t" + rminHeap.size());
            // find the current median
            median[i] = find(lmaxHeap , rminHeap) ;
            i++ ;

        }
        return median ;
    }
    protected int find(Queue<Integer> lmaxHeap , Queue<Integer> rminHeap){
        if(lmaxHeap.size() >= rminHeap.size() ) {
            return lmaxHeap.peek() ;
        }
        return rminHeap.peek() ;
    }
    protected void adjust(Queue<Integer> lmaxHeap , Queue<Integer> rminHeap) {
        int ls = lmaxHeap.size() ;
        int rs = rminHeap.size() ;
        if(Math.abs(ls - rs ) >= 2 ) {
            if(ls > rs) {
                int lmax = lmaxHeap.poll() ;
                rminHeap.offer(lmax) ;
            }else{
                int rmin  = rminHeap.poll() ;
                lmaxHeap.offer(rmin) ;
            }
        }
    }
    public static void main(String []args) {
        Solution sol = new Solution();
        int []nums = new int[] {5,-10,4} ;
        int []medians =sol.medianII(nums) ;
        for(int i = 0 ; i< medians.length ; i++ ){
            System.out.print(medians[i]+ " \t" ) ;
        }

    }
}

