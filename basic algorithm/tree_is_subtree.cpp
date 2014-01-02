/**
 * 判断树A 是否树B 的子树
 */ 
#include <iostream>
#include <stack> 
#include <cstdlib>
#include <string> 
#include <vector>
#include <queue> 
#include <sstream> 
using namespace std;

#define MAX_NODE 10
class TreeNode {
    public:
        TreeNode *left;
        TreeNode *right ; 
        TreeNode *parent; 
        int data; 
        int visitNum ; 

        //求左宽 右宽 用到的属性  
        int leftWidth;  //  
        int rightWidth; // 
        // 判断完全二叉树用的属性 
        int visitId ;

        //层序遍历 
        int level ; 
    public :
        TreeNode() {
            visitNum = 0 ;
            left = NULL;
            right = NULL ; 
            parent = NULL ;

            leftWidth = 0 ;  ;

            rightWidth = 0 ;
        }
        TreeNode(int data){
            this->data = data ;
            left = NULL ;
            right = NULL ; 
            parent = NULL ;
            visitNum = 0 ;

            leftWidth = 0 ;
            rightWidth = 0 ;
        }
};

bool IsSubtreeWithValue(TreeNode *pTree, TreeNode * sTree)
{
	if(sTree == NULL ) return true;
	if(pTree == NULL) return false ; 
	return ( pTree->data == sTree->data &&IsSubtree(pTree->left ,sTree->left ) && IsSubtree(pTree->right, sTree->right) ) 
	        || IsSubtree(pTree->left,sTree)  
			|| IsSubtree(pTree->right, sTree)  ;
} 
/**
*  只考虑结构的相似性  
*/
bool IsSubtree(TreeNode * pTree ,TreeNode * sTree ) 
{
    if(sTree == NULL ) return true; 
    if(pTree == NULL ) return false;
    return (IsSubtree(pTree->left ,sTree->left ) && IsSubtree(pTree->right, sTree->right)) || 
             IsSubtree(pTree->left,sTree)  || IsSubtree(pTree->right, sTree)  ;
}
int main()
{
    cout<<"MAX_NODE: " <<MAX_NODE<<endl;
    vector<TreeNode* > nodes  ; 
    for(int i = 0 ; i< MAX_NODE; i++ ) {
        TreeNode * node = new TreeNode(i); 
        nodes.push_back(node);
    }
    
    nodes[0]->left = nodes[1] ;  nodes[1]->parent = nodes[0]; 
    nodes[0]->right = nodes[2] ;  nodes[2]->parent = nodes[0] ; 

    nodes[1]->left = nodes[3] ;  nodes[3]->parent = nodes[1] ; 
     nodes[1]->right = nodes[4] ; nodes[4]->parent = nodes[1] ; 

    nodes[2]->left = nodes[5] ;  nodes[5]->parent = nodes[2] ; 
    nodes[2]->right = nodes[6] ;  nodes[6]->parent = nodes[2] ; 

	nodes[4]->right = nodes[7] ; nodes[7]->parent = nodes[4] ; 
 	nodes[6]->right = nodes[8] ; nodes[8]->parent = nodes[6] ;  
 	
 	nodes[7]->left = nodes[9] ;  nodes[9]->parent = nodes[7] ; 
 	
    int   p ,s  ; 
    while(true){
        cin>>p>>s ; 
        if(IsSubtree(nodes[p] , nodes[s])){
            printf("\t%d is Subtree of %d\n",s , p ) ;
        }else{
            printf("\tNot subtree\n");
        }
    }
    system("PAUSE");
}


