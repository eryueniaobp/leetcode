#include <iostream>
#include <stack> 
#include <cstdlib>
#include <string> 
#include <vector>
#include <queue> 
#include <sstream> 
#include <queue>
using namespace std;
#define MAX_NODE 20
/**
 * version 2.0  不使用优先队列 直接比较找到最小值 
 * O(|V|^2) 
 */ 
struct Node
{
    int id;  
    int dist ; 
    bool isClosed;
    Node() {
        id = -1 ; 
        dist = INT_MAX ; 
        isClosed = false;
    }
    bool operator< (const Node & node ) const {
        return !(this->dist < node.dist) ;
    }
};

class Graph
{
private :
public:
    int data[MAX_NODE][MAX_NODE];
    int nodeCount; 

    Node nodes[MAX_NODE] ;  // closedList[i] = node_id  

    Graph(int count ){
        if( count > MAX_NODE ) return ;

        nodeCount = count ; 
        for(int i = 0 ; i< nodeCount ; i++) {
            nodes[i].id = i ; 
            for(int j = 0 ; j< nodeCount ; j ++ ){
                data[i][j] = INT_MAX;
            }
        }
    }
    // @return 下一个最小节点的id
    int AddConnectedNodes(const Node & node)
    {
        // step 1 : update 
        int id = -1 ;
        int min = INT_MAX;
        for(int i = 0 ; i< nodeCount ; i++ ) {

            if(nodes[i].isClosed ) continue ; 

            int dist = node.dist + data[node.id][i] ;
            if(dist < 0)  dist = INT_MAX ; 

            if(dist < nodes[i].dist ){
                nodes[i].dist = dist ;
            }
            
            if(nodes[i].dist < min ) {
                min = nodes[i].dist ;
                id = i ; 
            }
        }
        return id ;
        // step 2 : add 
    }
    void Clear() 
    {
		for(int i = 0 ; i< nodeCount ; i++ ) 
		{
			nodes[i].isClosed = false; 
			nodes[i].dist = INT_MAX;
		}
	}
    int Shortest(int s , int e ) {
		Clear();
        nodes[s].dist = 0 ; 
        nodes[s].isClosed = true ; 
        int id = s; 
        while( (id = AddConnectedNodes(nodes[id]) ) != -1 ) {
            nodes[id].isClosed  = true;
            printf("%d is closed , dist = %d \n" , nodes[id].id , nodes[id].dist ) ;
        }
        return nodes[e].dist;
    }
    
};
int main()
{

	cout<<"MAX_NODE: " <<MAX_NODE<<endl;
    Graph *graph = new Graph(MAX_NODE) ;
    for(int i = 0 ; i< MAX_NODE; i++  )  
        for(int j = 0 ;j < MAX_NODE; j ++ ) 
        {
           graph->data[i][j] = rand()%1000  ;   
           if(graph->data[i][j] == 0 ) {
               graph->data[i][j] = INT_MAX  ; 
           }
           //cout<<graph->data[i][j]<<" " ; 
        }
        cout<<endl;
    int s = 0 , e = 0 ; 
    while(true) {
        cin>>s>>e; 
        cout<<"\t"<<graph->Shortest(s,e)<<endl; 
    }
    system("PAUSE");
}


