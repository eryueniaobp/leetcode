/* 系列题目: 一组数，缺了k个数，求找出这k个数  */
/* Q1.int A[N-1],数值范围 [1,N], 只缺少一个数，求出该数*/


/** 
 * 方案1 . N*(N+1)/2  -  sum(A[i])  有可能溢出 .. 
 *         考虑到数组本身是在内存的，受到内存限制，溢出可能性极小. 
 * 方案2 . xor(1~N) ^ A[i]  也能获得缺少的数 
 * 方案3 . 排序之后，扫一遍 采用换位的排序方法.  排序有 O(N)的方法
 * 方案4 . 按照桶排序的方法，设置一个 tag[N] ,然后tag[i] =1 表示有这个数，能处理缺少 K个数的方案，空间要求大
 */
// 方案2 
int find_lost_one(int A[] , int N ) {
	int size = N - 1 ; 
	int ret = 0 ;
	for(int i = 0 ; i< size ; i++ ) {
		ret ^= (i+1)^A[i] ; 
	}
	return ret^N; 
}
// 方案3  O(N)的方法排序了..
int find_lost_one(int A[],int N) {
	int size = N - 1;  
	int i = 0 ; 
	while(i < size ) {
		while( i< size &&  A[i] == i + 1 ) i ++ ; 
		while ( i< size && A[i] != i + 1 ) {
			if(A[i] -1 < size ) {
				swap(A[i] , A[A[i] - 1] ) ; 
			}else{
				i ++ ; 
				// break; 
			}
		}
	}
	for( i = 0 ; i < size ; i ++ ) {
		if(A[i] != i + 1 ) break;  
	}
	return i + 1; 
}

/*Q2 int A[N-2],数值范围 [1,N], 缺少两个数，求出这两个数 */
// 解决方案: O(N) 时间 O(1)空间  排序,然后求出这两个数字 
void find_lost_two(int A[] , int N,int & a ,int &b) {
	int size = N -2 ; 
	int i = 0 ; 
	while(i < size ) {
		while( i< size &&  A[i] == i + 1 ) i ++ ; 
		while ( i< size && A[i] != i + 1 ) {
			if(A[i] -1 < size ) {
				swap(A[i] , A[A[i] - 1] ) ; 
			}else{
				i ++ ; 
				// break; 
			}
		}
	}
	a = b = -1 ; 
	int tmp = -1; 
	for( i = 0 ; i < size ; i ++ ) {
		if(A[i] != i + 1 ) {
		//	break;  
			if(a == -1 ) {
				a = i + 1; 
				tmp = A[i] ; 
			}
			else b = i + 1 ; 
		}
	}
	if( a == -1 ) {
		a = N-1 ; 
		b = N ; 
		return ; 
	}
	if(b == -1 ) {
		b = N + N -1 - tmp ; 
	}
}


