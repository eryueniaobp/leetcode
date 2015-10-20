#include<queue>
#include<iostream>
using namespace std; 
const int MAXN = 1000 ; 
int used[MAXN] = { 0 }; 
int G[MAXN][MAXN] = {0} ; 
struct Node {
    int s,e ,cost ; 
    bool operator()(const Node &a,const Node&b ) {
        return a.cost > b.cost ; 
    }
}; 
/**
bool operator<(const Node &a,const Node&b ) {
    return a.cost > b.cost ; 
} 
or 
struct Node{
    // the last const is necessary.
    bool operator<(const Node& node) const {
        return cost > node.cost ; 
    }
}
priority_queue<Node> qe ; 
*/
int minimal_cost(int G[][MAXN],int N){
    priority_queue<Node,vector<Node>,Node> qe ; 
    int p = 0 ; 
    int mcost = 0 ; 
    while(true) {
        used[p]  = 1  ; 
        for(int i = 0 ; i< N ; i++){
            if(used[i] == 0 ) {
                qe.push((Node){p,i,G[p][i]}) ; 
            }
        }
        //find the unused one 
        
        while(!qe.empty()){
            Node node = qe.top() ;qe.pop() ;
            if ( used[node.e] == 0 ) {
                mcost += node.cost ;
                p = node.e ; 
                break; 
            }
        }

        if (qe.empty()) break; 

    }
    return mcost ; 
}
int main(){
    G[0][1] = 2 ; G[1][0] = 2 ;
    G[1][2] = 3 ; G[2][1] = 3 ; 
    G[0][2] = 4;  G[2][0] = 4 ;
    int cost = minimal_cost(G , 3 ) ; 
    cout<<cost<<endl ;
    system("pause");   
}

