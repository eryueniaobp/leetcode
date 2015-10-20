#include<iostream>
#include<string> 
#include<algorithm>
using namespace std; 
struct Node{
    int cnt ;
    int chr

};
bool cmp ( Node a , Node b) {
    if( a.cnt != b.cnt) {
        return b.cnt < a.cnt ;
    }
    return a.chr < b.chr ; 
}
int main(){
    string a ;
    cin>>a ; 
    Node nodes[26] ;
    for(int i = 0 ;i<26 ; i++ ) {
        nodes[i].cnt = 0 ;
        nodes[i].chr = i ; 
    }
    for(int i = 0 ;i < a.size() ;i ++ ) {
        nodes[ a[i] - 'a' ].cnt ++ ;
    }
    sort(nodes,nodes + 26 ,cmp) ;
    return 0;
}
