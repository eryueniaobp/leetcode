/**
 * Case 1: 
 *  
 *  t = a[i]&&i is single =>  return i ; 
 * Case 2: 
 *  t != a[i]  return j , (满足: a[j] > t, j最小) 
 * Case 3: 
 *  t = a[i]&& i isnot single : 
 *      如果要返回 最右端的值： if ( t>= a[mid] )  l=mid+1;   
 *                              return l-1; 
 *      如果要返回最左端的值：  if  ( t<=a[mid] ) r = mid;  
 *                              return l ; 
 *  
 * */
int find(int *a,int len ,int t ) {
	int l = 0 ; 
	int r = len;
	int mid = -1;
	while( l < r){
		mid = (l+r)/2;
		if( t < a[mid] ) {
			r = mid;
		}else if( t> a[mid] ) {
			l = mid +1; 
		}else{
			break;
		}
	}
	return (l+r)/2;
}

