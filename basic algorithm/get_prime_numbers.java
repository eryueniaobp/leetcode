/*
Amazon Sample Test 
Complete the function getNumberOfPrimes which takes in an integer N as its parameter, 
to return the number of prime numbers that are less than N
*/
static int getNumberOfPrimes(int N) {
    List<Integer> nums = new ArrayList<Integer>() ;
    nums.add(2) ; 
    for(int i = 3 ;  i < N ; i++) {
        boolean isPrime = true; 
        int up  = (int) Math.sqrt((double) i ) ; // critical . can reduce the time cost.
        for(Integer p : nums) {
            if( i %p == 0 ) {
                isPrime = false; 
                break; 
            }
            if( p > up) break ; 
        }   
        if(isPrime) nums.add(i) ; 
    }
    return nums.size() ; 
}

