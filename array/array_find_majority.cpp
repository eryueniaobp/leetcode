/* 整体上这类问题都是匹配问题,N个不一样的，就把这N个都消掉 */

/*Q1. int A[N] ,有一个数出现次数超过一半 ，求出该数 */
int find_majority(int A[],int N ) {
	int ret = A[0] ; int count = 1 ; 
	for(int i = 1 ; i< N ; i ++ ) {
		if(count == 0 ) {
			ret = A[i] ; 
			count =1 ; 
		}else{
			if(A[i] != ret ) {
				count -- ; 	
			}else {
				count ++ ; 
			}
		}
	}
	return ret; 
}
/* Q2. int A[N], 仅有一个数出现次数超过1/3 ,求出该数 */  
typedef struct  {
	int val ; 
	int cnt ; 
} Ele;
int find_one_third_more(int A[] , int N ) {
	//assert( N >= 3 ) ; 
	Ele ele[2] ; ele[0].cnt = 1 ; ele[0].val = A[0] ;  
	int i = 1 ; 
	while( i < N && A[i] == A[i-1] ) {  i ++  ; ele[0].cnt ++; }  
	ele[1].val = A[i] ; ele[1].cnt = 1 ; 
	
	for( i++ ; i <N ; i ++ ) {
		if(ele[0].cnt > 0 && A[i] == ele[0].val ) ele[0].cnt ++ ; 
		else if(ele[1].cnt >0 && A[i] == ele[1].val ) ele[1].cnt ++ ; 
		else {
			if(ele[0].cnt == 0) {
				ele[0].cnt =1; ele[0].val = A[i] ; 
			}else if(ele[1].cnt == 0 ) {
				ele[1].cnt =1 ; ele[1].val = A[i] ; 
			}else {
				ele[0].cnt -- ; 
				ele[1].cnt -- ; 
			}
		}
	}
	return ele[0].cnt > ele[1].cnt ? ele[0].val : ele[1].val ;
}

