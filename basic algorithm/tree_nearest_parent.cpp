
#include <iostream>
#include <stack> 
#include <cstdlib>
#include <string> 
#include <vector>
#include <queue> 
#include <sstream> 
using namespace std;
class TreeNode {
    public:
        TreeNode *left;
        TreeNode *right ; 
        TreeNode *parent; 
        int data; 
        int visitNum ; 

        // 判断完全二叉树用的属性 
        int visitId ;
    public :
        TreeNode() {
            visitNum = 0 ;
            left = NULL;
            right = NULL ; 
            parent = NULL ;
        }
        TreeNode(int data){
            this->data = data ;
            left = NULL ;
            right = NULL ; 
            parent = NULL ;
            visitNum = 0 ;
        }
};

TreeNode* nearestParent(TreeNode* a , TreeNode* b ) 
{
	if( a== NULL || b == NULL ) return NULL ;
	stack<TreeNode* > path1 , path2; 
	while(a != NULL ) {
		path1.push(a) ; 
		a = a->parent; 
	}
	while(b != NULL ) {
		path2.push(b);
		b = b->parent; 
	}
	TreeNode *parent = NULL ; 
	while(!path1.empty() && !path2.empty()) {
		TreeNode *t1 = path1.top() ; path1.pop();
		TreeNode *t2 = path2.top() ; path2.pop() ; 
		if( t1 == t2 ) {
			parent = t1 ; 
			continue;
		}else{
			return parent; 
		}
	}
	return parent;
}

int main()
{
    vector<TreeNode* > nodes  ; 
    for(int i = 0 ; i< 8 ; i++ ) {
        TreeNode * node = new TreeNode(i); 
        nodes.push_back(node);
    }
    for(int i = 0 ;i< 8 ; i++){
        cout<< nodes[i]->data << " " ;
    }
    cout<<endl;
    nodes[0]->left = nodes[1] ;  nodes[1]->parent = nodes[0]; 
    nodes[0]->right = nodes[2] ;  nodes[2]->parent = nodes[0] ; 

    nodes[1]->left = nodes[3] ;  nodes[3]->parent = nodes[1] ; 
    nodes[1]->right = nodes[4] ; nodes[4]->parent = nodes[1] ; 

    nodes[2]->left = nodes[5] ;  nodes[5]->parent = nodes[2] ; 
    //nodes[2]->right = nodes[6] ;  nodes[6]->parent = nodes[2] ; 


 //	nodes[3]->left = nodes[7] ;  
    TreeNode* parent = nearestParent(nodes[2],nodes[3]) ; 
   	cout<<"Parent is " << parent->data <<endl ;
    system("PAUSE");
}









