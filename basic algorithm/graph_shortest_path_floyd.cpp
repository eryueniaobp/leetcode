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
 * Floyd  
 * O(|V|^3) 
 * Tip: 缺少负环检测
 */ 

class Graph
{
private :
public:
    int data[MAX_NODE][MAX_NODE];
    int nodeCount; 

    int dist[MAX_NODE][MAX_NODE] ;

    Graph(int count ){
        if( count > MAX_NODE ) return ;

        nodeCount = count ; 
        for(int i = 0 ; i< nodeCount ; i++) {
            
            for(int j = 0 ; j< nodeCount ; j ++ ){
                data[i][j] = INT_MAX;
                dist[i][j] = INT_MAX;
            }
        }
    }
    int Query(int s , int e ) 
    {
        return dist[s][e] ;
    }
    void Clear() 
    {
        for(int i = 0 ; i< nodeCount ; i++ ) 
            for(int j = 0 ; j<nodeCount ; j++ ) 
            {
                dist[i][j] = data[i][j];
                if( i == j ) {
                    dist[i][j] = 0 ;
                }
            }
	}
    void FloydShortest() {
		Clear();
        for(int k = 0 ; k < nodeCount ; k++ ) 
            for(int i = 0 ; i < nodeCount ; i++ )
                for(int j = 0 ; j<nodeCount ; j ++ ) 
                {
                    int cur = dist[i][k] + dist[k][j];

                    if(cur < 0 ) cur = INT_MAX ;
                    if(cur < dist[i][j] ) {
                        dist[i][j] = cur; 
                    }
                }
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
    graph->FloydShortest()  ;
    int s = 0 , e = 0 ; 
    while(true) {
        cin>>s>>e; 
        cout<<"\t"<<graph->Query(s,e)<<endl; 
    }
    system("PAUSE");
}

