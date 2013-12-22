
#include <iostream>
#include <stack> 
#include <cstdlib>
#include <string> 
#include <vector>
using namespace std;
class TreeNode {
public:
	TreeNode *left;
	TreeNode *right ; 
    TreeNode *parent; 
	int data; 
	int visitNum ; 
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
//  中序遍历下的后继节点  bst 中的后继节点
TreeNode * nextNodeOfMiddleOrder(TreeNode * node ){
    if( node == NULL ) return NULL;  
    if(node->right != NULL ) {
        node = node->right; 
        while(node->left != NULL ) {
            node = node->left; 
        }
        return node ;
    }
    
    while ( node->parent != NULL && node->parent->right == node ) {
        node = node->parent; 
    }
    return node->parent; 
}

//  前序遍历下的后继节点 
TreeNode * nextNodeOfPreOrder(TreeNode *node ) {
    if(node == NULL ) return NULL ; 
    if(node->left != NULL ) return node->left  ;
    if(node->right != NULL ) return node->right;  

    while( node->parent != NULL && node->parent->right == node ){
        node = node->parent ; 
    }
    if( node->parent == NULL ) return NULL ; 
    return node->parent->right; 
}

//  后续遍历下的后继节点 
TreeNode * nextNodeOfPostOrder(TreeNode *node){
    if(node == NULL )return NULL ; 
    // node 的子树都已经遍历了，只需要考虑node 的以上部分
    if(node->parent == NULL ) return NULL ; 
    if(node->parent->right == node || node->parent->right == NULL ) return node->parent ; 
    node = node->parent->right;

    while( node->left != NULL || node->right != NULL   ) {
        if(node->left !=NULL ) node = node->left  ;
        else{
            node = node->right;
        }
    }
    return node ;
}
void print(TreeNode *node ) {
    if( node == NULL ) cout<<"NULL"<<endl;
    else {
        cout<<node->data<<endl;
    }
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

	nodes[3]->left = nodes[5] ;  nodes[5]->parent = nodes[3] ; 
	nodes[3]->right = nodes[6] ;  nodes[6]->parent = nodes[3] ; 

	nodes[4]->right = nodes[7] ;  nodes[7]->parent = nodes[4] ;
    TreeNode * next = nextNodeOfMiddleOrder(nodes[7]) ; 
    cout<< next->data << endl ;   // 0 
    next = nextNodeOfMiddleOrder(nodes[3]) ; 
    cout<< next->data <<endl ;  // 6

    next = nextNodeOfMiddleOrder(nodes[6]) ; 
    cout<< next->data<<endl; // 1 

    next = nextNodeOfMiddleOrder(nodes[2]) ; 
    if( next == NULL ) {
        cout<< "NULL" <<endl;  // NULL  
    }

    cout<<" Next_Node_Of_PreOrder : " <<endl;
    next = nextNodeOfPreOrder(nodes[7] )  ; 
    print(next)  ;
    next = nextNodeOfPreOrder(nodes[3] ) ; 
    print(next)  ; 
    next = nextNodeOfPreOrder(nodes[6]) ; 
    print(next) ; 
    next = nextNodeOfPreOrder (nodes[2] ) ; 
    print(next) ;

    cout<<" Next_Node_Of_PostOrder : " <<endl;
    next = nextNodeOfPostOrder(nodes[7] )  ; 
    print(next)  ;
    next = nextNodeOfPostOrder(nodes[3] ) ; 
    print(next)  ; 
    next = nextNodeOfPostOrder(nodes[6]) ; 
    print(next) ; 
    next = nextNodeOfPostOrder(nodes[2] ) ; 
    print(next) ;


	system("PAUSE");
}


