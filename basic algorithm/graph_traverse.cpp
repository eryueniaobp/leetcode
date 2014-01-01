#include <iostream>
#include <stack> 
#include <cstdlib>
#include <string> 
#include <vector>
#include <queue> 
#include <sstream> 
#include <queue>
#include <map>
using namespace std;
#define MAX_NODE 20

class Graph
{
public:
    int data[MAX_NODE][MAX_NODE];
    int nodeCount; 
    bool *visited;        

    Graph(int count ){
        if( count > MAX_NODE ) return ;

        nodeCount = count ; 
        for(int i = 0 ; i< nodeCount ; i++) {
            for(int j = 0 ; j< nodeCount ; j ++ ){
                data[i][j] = INT_MAX;
            }
        }
    }


    void Visit(int s) {
        cout<<s<<" " ; 
        visited[s] = true;
    }
    
    /**
     * 只能遍历 包括 s 的连通图 
     */ 
    void Traverse_BFS(int s) {
        visited = new bool[nodeCount] ; 
        memset(visited,0 ,nodeCount*sizeof(bool)) ;

        queue<int> q; 
        q.push(s);  
        Visit(s) ; 

        while(!q.empty()) {
            int cur = q.front(); q.pop(); 
            for(int i = 0 ; i< nodeCount ; i++ ) {
                if( i == cur ) continue; 
                if( !visited[i] && data[cur][i] != INT_MAX ) {
                    Visit(i); 
                    q.push(i); 
                }
            }
        }
        delete [] visited ;
    }
	void RecursiveTraverse(int s){
		Visit(s); 
		for(int i = 0 ; i< nodeCount ; i++){
			if( i == s ) continue ; 
			if(!visited[i] && data[s][i] != INT_MAX ){
				RecursiveTraverse(i) ;
			}
		}
	};
    void Traverse_DFS(int s){
        visited = new bool[nodeCount];
        memset(visited , 0 ,nodeCount * sizeof(bool)) ; 
		RecursiveTraverse(s) ;
		cout<<endl<<"\t";
		memset(visited , 0 ,nodeCount * sizeof(bool)) ;   
		
		
        stack<int> st  ;  map<int,int> n2c ;
        Visit(s);
        st.push(s); n2c[s] = 0 ;
        while(!st.empty()){
            int cur = st.top() ; 
            if(n2c[cur] == nodeCount ) {
                st.pop(); 
                continue;
            }
            for(int i = n2c[cur] ; i < nodeCount ; i++) {
                n2c[cur] = i + 1;
                if( i == cur) continue; 
                if(!visited[i] && data[cur][i] != INT_MAX ) {
                    Visit(i) ; 
                    n2c[cur] = i + 1;

                    st.push(i) ; n2c[i] = 0 ;

                    break;
                }
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
           if(graph->data[i][j] < 600 ) {
               graph->data[i][j] = INT_MAX  ; 
           }
        }
	int s = -1 ;
	while(true) {
		cin>>s; 
		cout<<"\t";
    	graph->Traverse_DFS(s);
    	cout<<endl;
	}
    system("PAUSE");
}

