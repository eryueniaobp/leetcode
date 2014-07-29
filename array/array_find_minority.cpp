/*
ϵ����Ŀ�����ĵ����ζ������滻Ϊ ż���� . 

Q1:  int A[N] , ֻ��һ����������һ�Σ���������������Σ������һ�ε��� .  
*/ 
int find_single_num(int A[] , int N) {
	int ret = 0 ; 
	for(int i =  0 ; i< N ; i ++ ){
		ret = ret ^ A[i] ; 
	}
	return ret; 
}
/* Q2 :  int A[N] ,��������������һ�Σ���Ķ��������Σ�����������*/ 
/*
 * ����� eor = a^b , Ȼ����eor�����λ1��ԭ����ֵ����� �� ÿ�߶����� ��򣬾���� a �� b �� .
 */
void find_pair(int A[],int N , int &a ,int &b ) {
	int eor = 0 ; 
	for(int i = 0 ; i< N ; i++ ) {
		eor = eor ^ A[i] ; 
	}
	
	int low = eor - (eor & ( eor -1 ) );   // & �Ĳ������ȼ��ܵ͵ģ����������������  
	
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
/*Q3 : int A[N] , ��������������һ�Σ���Ķ������Σ����������� */
/*
 *  1.  eor = a^b^c  , 
 *  2.  a ^ eor = b^c ; b ^ eor = a^c ; c ^ eor = a^b 
 *  3.  (b^c) ^(a^c)^ ( a^b) =  0   => ��ȥ���ҵ�0��׺����Ȼ������1 ��һ��0  . ��λ�����?  
 *  http://www.cnblogs.com/luxiaoxun/archive/2012/09/08/2676610.html ����ط�д�ñȽ���ϸ . 
 * 
 */
void find_triple(int A[],int N, int &a,int &b,int &c) {
}

