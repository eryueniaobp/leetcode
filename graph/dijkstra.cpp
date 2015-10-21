#include<queue>
#include<iostream>
using namespace std;
const int MAXN = 1000 ; 
int used[MAXN] = {0 } ; 
int G[MAXN][MAXN] = {0} ; 
int dist[MAXN] = {0} ; 
struct Node{
int s ,e , cost ; 
bool operator< (const Node & a ) const {
    return cost > a.cost ;
}
};
priority_queue<Node> qe ; 
void update_dist(int N,int s) {
    for(int i = 0 ; i< N ; i++){
        if(used[i] == 0 && ( dist[i]==-1 ||  dist[s] + G[s][i] <dist[i]) ) {
            dist[i] = dist[s] + G[s][i]; 
            qe.push((Node){s,i,dist[i]});
        }
    }
}
void dijkstra(int G[][MAXN],int N , int s){
    fill(dist,dist+N ,-1) ;
    dist[s] = 0 ; 
    used[s] = 1; 
    update_dist(N,s) ;
    while(!qe.empty()) {
        Node node = qe.top() ;qe.pop() ;
        if(used[node.e] == 0 ){
            used[node.e] = 1 ; 
            update_dist(N,node.e) ;
        }
    }
}
int main(){
    int N = 3; 
    G[0][1] = 2 ; G[1][0] =2 ; 
    G[1][2] = 1 ; G[2][1] =1 ;
    G[0][2] = 4 ; G[2][0] = 4 ;
    dijkstra(G,N, 0 ) ;
    for(int i =  0 ; i< N ; i++){
        cout<<dist[i]<<endl;
    }
    return 0;
}
