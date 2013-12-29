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
 * version 1.0  使用优先队列的版本 
 * 注意: 更新邻点的dist时，可以直接向队列中插入新节点。如果要先删除再插入的话，反而增加运行时间
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
    priority_queue<Node, vector<Node> >  distQueue;
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
    void AddConnectedNodes(const Node & node)
    {
		//while(!distQueue.empty())  distQueue.pop();
        // step 1 : update 
        for(int i = 0 ; i< nodeCount ; i++ ) {

            if(nodes[i].isClosed ) continue ; 

            int dist = node.dist + data[node.id][i] ;
            if(dist < 0)  dist = INT_MAX ; 

            if(dist < nodes[i].dist ){
                nodes[i].dist = dist ;
				distQueue.push(nodes[i]) ; 
            }

            
        }
        // step 2 : add 
    }
    void Clear() 
    {
		while(!distQueue.empty() ) 
		{
			distQueue.pop();
		}
		for(int i = 0 ; i< nodeCount ; i++ ) 
		{
			nodes[i].isClosed = false; 
			nodes[i].dist = INT_MAX;
		}
	}
    int Shortest(int s , int e ) {
		Clear();
        nodes[s].dist = 0 ; 
        distQueue.push(nodes[s]) ; 
        while(!distQueue.empty() ) {
            Node node = distQueue.top() ;  distQueue.pop() ; 
            int id = node.id ; 
            if(nodes[id].isClosed) continue ; 
            
            nodes[id].isClosed  = true;
            printf("%d is closed , dist = %d \n" , nodes[id].id , nodes[id].dist ) ;
//            cout<<nodes[id].id<< " is Closed " <<endl;
            AddConnectedNodes(nodes[id]);
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
        }
    int s = 0 , e = 0 ; 
    while(true) {
        cin>>s>>e; 
        cout<<"\t"<<graph->Shortest(s,e)<<endl; 
    }
    system("PAUSE");
}

