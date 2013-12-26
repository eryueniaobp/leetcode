#include <iostream>
#include <stack> 
#include <cstdlib>
#include <string> 
#include <vector>
#include <queue> 
#include <sstream> 
using namespace std;

#define MAX_WORD_LEN 30 
class Node{
public:
    int endCount ;
    int count; 
    Node** children ;
    Node(){
		
        children = new Node*[26];
        for(int i = 0 ; i< 26 ; i++ ) {
			children[i] = NULL ;
		}
        endCount = 0 ;
        count = 0 ;
    }
};
class Trie{
public:
    Node **entry;
    Trie(){
		entry = new Node*[26] ;
		for(int i = 0 ; i< 26 ;i ++ ){
			entry[i] = NULL ;
		}
    }
    void add(const char * word,int len){
        
        Node **pool = entry;
        int  i =  0  ,pos =  0 ; 
        while(i < len ) {
            pos = word[i] - 'a' ; 
            if(pool[pos] == NULL ){
            	pool[pos] = new Node() ;
			}
            pool[pos]->count++ ;  
            if( i == len -1   ) {
                pool[pos]->endCount ++ ;
            }
            pool = pool[pos]->children;
            i++;
        }
    }
    int query(const char *word,int len){
        
        Node **pool = entry;
        int count = 0 , pos = 0 ; 
        for(int  i= 0  ; i< len  ; i++ ){
            pos = word[i] - 'a' ; 
            if(pool[pos] == NULL || pool[pos]->count <= 0 ) {

                return 0; 
            }
            count = pool[pos]->endCount ;
            pool = pool[pos] ->children; 
        }
        return count; 
    }

};
int main() 
{
    Trie trie ;
    int count = 100 ; 
    while( count -- ) {
        int len = rand()%10 + 1  ; 
        char * word = new char[len+1] ;
        word[len] = 0 ;
        for(int i = 0 ; i< len   ; i++ ) {
            word[i] = rand()%26 + 'a' ;
        }
        cout<<count<<"\t"<<word<<endl; 
        trie.add(word,len) ;
    }
    cout<<endl;  
	trie.add("meayl",5);
    while(true) {
        string query  ; 
        cin>> query ; 
        cout<<"\t"<<trie.query(query.data(),query.size() ) <<endl;
            
	}
    return 0 ;
}


