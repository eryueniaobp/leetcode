/*
系列题目：下文的两次都可以替换为 偶数次 . 

Q1:  int A[N] , 只有一个数出现了一次，别的数都出现两次，求出现一次的数 .  
*/ 
int find_single_num(int A[] , int N) {
	int ret = 0 ; 
	for(int i =  0 ; i< N ; i ++ ){
		ret = ret ^ A[i] ; 
	}
	return ret; 
}
/* Q2 :  int A[N] ,有两个数出现了一次，别的都出现两次，求这两个数*/ 
/*
 * 先求出 eor = a^b , 然后拿eor的最低位1将原数组分到两边 ， 每边都再求 异或，就求出 a 和 b 了 .
 */
void find_pair(int A[],int N , int &a ,int &b ) {
	int eor = 0 ; 
	for(int i = 0 ; i< N ; i++ ) {
		eor = eor ^ A[i] ; 
	}
	
    int low = eor & (eor ^ ( eor - 1)) ;	
	int i = 0 , j = N -1 ; 
	while ( i < j ) {
		while( i < N && (A[i] & low) == low )  i ++ ; // low maybe Integer.MIN_VALUE . must check == low
		while( j >=0 && (A[j] & low) == 0 ) j--;  
		if( i <j ) swap(A[i],A[j]) ; 
	}
	 
	a = 0 ; 
	for(int  k = 0 ; k < i ; k ++ ) {
		a = a^A[k] ; 
	}
	b = 0 ; 
	for (int k = i ; k < N ; k ++ ){
		b = b^A[k] ; 
	}
}
/*Q3 : int A[N] , 有三个数出现了一次，别的都是两次，求这三个数 */
/*
 *  1.  eor = a^b^c  , 
 *  2.  a ^ eor = b^c ; b ^ eor = a^c ; c ^ eor = a^b 
 *  3.  (b^c) ^(a^c)^ ( a^b) =  0   => 除去最右的0后缀，必然是两个1 ，一个0  . 如何划分呢?  
 *  http://www.cnblogs.com/luxiaoxun/archive/2012/09/08/2676610.html 这个地方写得比较详细 . 
 * 
 */
void find_triple(int A[],int N, int &a,int &b,int &c) {
}
/**
* Q4: int A[N] , N = 3*n + 1  , only one number occurs one time . others occur 3 times each . 
* http://lintcode.com/zh-cn/problem/single-number-ii/
*/
public class Solution {
	/**
	 * @param A : An integer array
	 * @return : An integer 
	 */
    public int singleNumberII(int[] A) {
        // write your code here
        int []bits = new int[32]; Arrays.fill(bits, 0) ; 
        for(int i = 0 ;i < A.length ; i++){
            for(int j = 0 ; j < 32 ; j++ ) {
                bits[j] += ((A[i]>>j)&1); 
            }
        }
        int ret =  0 ; 
        for(int j = 0 ; j< 32 ; j++){
            if(bits[j] % 3 != 0 ) {
                ret |=  (1<<j) ;
            }
        }
        return ret ; 
    }
}
