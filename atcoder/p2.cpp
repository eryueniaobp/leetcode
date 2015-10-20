#include<iostream>
#include<string> 
#include<algorithm>
using namespace std; 
struct Tag{
    int t  ; 
    int pos ; 
    
};

int main(){
    // 1234 5678 123 12345 9876 
    int A , B ,X1 , K , M; 
    cin>>A>>B>>X1>>K>>M ; 
    int *buf = new int[M + 1]; 
    Tag *tag = new Tag [M + 1] ;
    for(int i = 0 ; i< M  + 1 ; i++ ) {
        tag[i].t  = 0 ; 
        tag[i].pos = 0 ; 
        
        buf[i] = 0 ;  
    }
    
    buf[0] = X1 ; 
    tag[ X1].t = 1 ; 
    tag[X1].pos = 0 ; 
    
    int LEN = 0 ; 
    int start = 0 ; 
    for(int i = 1 ; i <= M  ; i++ ) {
        buf[i] =  ( A * buf[i-1] + B ) % M ; 
        if( tag[ buf[i] ].t  == 1  ) {
            start = tag[ buf[i] ].pos ; 
            LEN = i - start ;   
            break;  
        }
        tag[buf[i]].t = 1 ; 
        tag[buf[i]].pos = i ; 
       //  cout<<" i= " << i<<endl; 
    }
//     cout<<"break LEN= " << LEN <<endl << " start= " << start<<endl; 
    if( K <= start ) {
        cout<< buf[ K-1] <<endl <<buf[K] <<endl <<buf[K+1]<<endl<<buf[K+2]<<endl;
        return 0 ; 
    }
    K = K - start ; 
    for( int i = K-1 ; i < K + 4 ; i++ ) {
        // cout<<" ind = " << i%LEN <<endl; 
        cout<< buf[start + i%LEN] <<endl ;
    }
  //  system("pause") ;
    return 0;
}

