

#include <iostream>
#include <stack> 
#include <cstdlib>
#include <string> 
#include <vector>
#include<algorithm>
#include <ctime>
using namespace std;

// 返回 最终排序好的某个位置 ,这个很关键. 
int partition(int data[], int l,int r ) 
{
	
	if ( l == r -1 ) return l ; 
    int pos = l ; 
    int pivot = data[pos] ; 
    int pl = l , pr = r -1 ; 
	
    while(pl < pr ) {
        while(pl< r && data[pl] <= pivot ) pl ++ ;
        while(pr>=l && data[pr] > pivot ) pr -- ; //if >= ? 
        if( pl < pr ) {
            swap(data[pl],data[pr]) ; 
        }
    }
	 // 关键一步： [l,pl) <= pos . 并且 pl-1是合适位置.. data[pos]的最终位置确定 	
	// 如果这里不交换，那么 3 , 2 , 1，选 3为 pivot,则 pl -1 =2, 最终会保持倒序.
	swap(data[pos] ,data[pr]) ;
    return pr  ; 
}
void qsort(int data[] , int l,int r) 
{
   
	if( l >=  r ) return ;
    int pos = partition(data, l , r) ;  
    qsort(data, l , pos) ;
    qsort(data, pos+1,r); 
}
void print(int data[]  ,int len ) 
{
	for(int i = 0 ; i< len ;i++ )
	{
		cout<<data[i] << " ";
	}
	cout<<endl;
}

void merge_sort(int data[],int l,int r)
{
	if( r - l <=1 )  return ;
	int pos = (l+r)/2;
	merge_sort(data, l , pos ) ; 
	merge_sort(data, pos, r ) ; 

	// merge 
	int * a = new int[r-l];
	int k = 0 ; 
	int i = l , j = pos; 
	while( i < pos && j < r ) 
	{
		if(data[i] < data[j] ) {
			a[k++] = data[i++] ; 
		}else{
			a[k++] = data[j++] ;
		}
	}
	while ( i < pos) a[k++] = data[i++] ; 
	while( j<r) a[k++] = data[j++] ;

	//copy to data 
	i = l  ; 
	while( i < r ) {
		data[i] = a[ i - l ] ;
		i++ ;
	}
	delete [] a;
}
//41 467 334 500 169  
//recursively
#define MAX_LEN 10000
int main()
{
	srand(time(NULL));
	int data[MAX_LEN] = {} ;
	int mirror[MAX_LEN] ={} ; 
	for(int i = 0 ; i< MAX_LEN ; i++ )
	{
		data[i] = rand() % 1000 ;
		mirror[i] = data[i] ;
		//cout<<data[i]<<" "; 
	}
	cout<<endl;

	//sort(data,data+MAX_LEN,greater<int>());
	//qsort(data, 0 , MAX_LEN ) ;
	merge_sort(data,0,MAX_LEN);
	sort(mirror,mirror+MAX_LEN);
	cout<<"After sort: " <<endl;
	int  i  ; 
	for( i = 0 ; i< MAX_LEN ;i++ )
	{
		//cout<<data[i]<<" " ; 
		if( data[i] != mirror[i] ) {
			cout<<"Erro!!"<<endl;
			break;
		}
	}
	cout<<endl;
	cout<<i<<endl;
	cout<<endl;
	/*sort(data,data+MAX_LEN);
	for(int i = 0 ; i< MAX_LEN ;i++ )
	{
		cout<<data[i]<<" " ; 
	}*/
	cout<<endl;

}
