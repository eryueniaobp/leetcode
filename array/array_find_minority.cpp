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
	
	int low = eor - (eor & ( eor -1 ) );   // & 的操作优先级很低的，必须用外面的括号  
	
	int i = 0 , j = N -1 ; 
	while ( i < j ) {
		while( i < N && (A[i] & low) > 0 )  i ++ ;
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

