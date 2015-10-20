#include<iostream>
#include<string> 
#include<algorithm>
using namespace std; 
int G[21][21] = {0 };
int N , Q  ; 
int T[21] = { 0 } ; // tag
bool query(int a , int b , int v ) {
    if( a == b ) return true ; 
    T[a] =  1  ; 
    for( int i = 1 ; i <= N ; i++ ) {
        if ( i == a || T[i] == 1 || G[a][i] < v ) continue; 
        if ( query ( i , b , v ) ) {
            T[a] = 0 ;
            return true; 
        }
    }
    T[a] = 0 ; 
}
int main(){
    cin >> N>>Q; 
    for(int i = 0 ; i< Q ; i++ ){
        string action; 
        int a , b , v ; 
        cin>>action>>a>>b>>v ; 
        cout<<action  ; // todo 
        if(action.compare("make") == 0 ) {
            if(G[a][b] < v ) {
                G[a][b] = v ; 
                G[b][a] = v; 
            }
        }else {
            if ( query( a, b , v ) ) {
                cout<<"YES"<<endl; 
            }else{
                cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}

