/**
solution1:  sort by start_ i ;  and then use a priority queue to get the latest end_i   , pop the conference with end_i. and insert the current conference to the queue.  

solution 2:  [si , ei]  =>  [ si  ,  [si,ei] ]  , [ ei ,[si,ei] ]  

transform N conference   to 2*N nodes.    and sort the 2*N nodes. 

if the node is start, then cnt++  ; if node is end_type ,then cnt--; 



the max cnt is the value of conferences. 

*/
#include<iostream>
#include<cstdlib>
 #include<algorithm>

using namespace std;

struct M{

	int s;
	int t;};

int main(){

	int n ;
	int *s ,*t; 
	cin>>n;
	s = new int[n];
	t = new int[n];
	int i = 0 ; 
	while(i<n){
		cin>>s[i];
                cin>>t[i];
                i++;
	}	
	sort(s,s+n);
	sort(t,t+n);
	int j = 0 ; 
	int num = 0 ;//return  
	for(int i = 0 ; i<n;){
		if(s[i] < t[j] ) {
			i++;
			num++;
		}else{
			i++;j++;
		}
	}
	cout<<num<<endl;
	return 0;
} 
