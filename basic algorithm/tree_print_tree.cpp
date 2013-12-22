
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

void printSpaces(int num ) {
    for(int i = 0 ; i < num ; i++ ) {
        cout<<" ";
    }
}

void printNode(TreeNode *node){
    printSpaces(node->leftWidth * 2); 
    cout<<node->data;
    printSpaces(node->rightWidth *2 );
}
/**
 * 根据 nearestParent(preNode,node),为preNode添加右空格, 为node添加左空格
 */
void addLayoutSpaces(TreeNode* preNode , TreeNode* node){
    if(preNode == NULL || node == NULL  ) return;  
    if(preNode->data == 1 ) {
		int a = 1 ;
	}
    int right = 0 , left = 0 ; 
    if(preNode->level != node->level ) {
		//node left 
		while(node->parent!= NULL ) {
			if(node->parent->right == node ) left += (node->parent->leftWidth + 1) ;
			node = node->parent ; 
		}
		printSpaces(left * 2) ;
		return; 
	}
    if(preNode == node ) return ; 
    
    // 保证是同级的 
    while(preNode!= node ) {
        if(preNode->parent->left == preNode) right+= ( preNode->parent->rightWidth +1 )  ;
        if(node->parent->right == node ) left += (node->parent->leftWidth + 1 );  

        preNode = preNode->parent ; 
        node = node->parent; 
    }
    
    right = right - node->rightWidth ; 
    left = left - node->leftWidth;
   
   	
    //printf("Pre=%d Cur=%d right=%d left=%d spaces=%d\n" , preNode->data, node->data,right,left, (right*2+ max(0,left*2-1)) ) ;
    // cout<<"Pre = " << preNode->data <<" Cur="<<node->data<<" right=" <<endl; 
    // 找到父节点了 
    printSpaces( (right + left  ) *2 -1) ; 
    

}
/** 
 * 打印完整的树
 * 出队列的时候打印
 */ 
void printTree(TreeNode * root) {
    if(root == NULL ){
        cout<<"Empty Tree"<<endl;
        return;
    }
    queue<TreeNode*> queue ;

    int levelNum = 1 , count = 0 ;
    root->level = 0;
    queue.push(root) ; 
    
    TreeNode *node = NULL  , *preNode = NULL ;   
    while(!queue.empty()){
        node = queue.front(); queue.pop(); levelNum-- ;
        
        addLayoutSpaces(preNode, node) ;  // key function
        printNode(node) ;
		preNode = node ;
        if(node->left!=NULL){
		    node->left->level = node->level + 1; 	
            queue.push(node->left);
            count++;
        }

        if(node->right != NULL){
            node->right->level = node->level +1 ; 
            queue.push(node->right);
            count++;
        }

        if(levelNum == 0 ) {
			cout<<endl;
            levelNum = count ; 
            count = 0 ;
        }
    }

}

void computeWidth(TreeNode * root) {  
    if(root == NULL )  return ; 
    computeWidth(root->left) ; 
    if(root->left!= NULL ){
	    root->leftWidth =  1 + root->left->leftWidth + root->left->rightWidth; 
    }
    computeWidth(root->right) ;
    if(root->right !=NULL ){
        root->rightWidth = 1+ root->right->leftWidth + root->right->rightWidth; 
    }
}

int main()
{
    vector<TreeNode* > nodes  ; 
    for(int i = 0 ; i< 10 ; i++ ) {
        TreeNode * node = new TreeNode(i); 
        nodes.push_back(node);
    }
    for(int i = 0 ;i< 10 ; i++){
        cout<< nodes[i]->data << " " ;
    }
    cout<<endl;
    nodes[0]->left = nodes[1] ;  nodes[1]->parent = nodes[0]; 
    nodes[0]->right = nodes[2] ;  nodes[2]->parent = nodes[0] ; 

    nodes[1]->left = nodes[3] ;  nodes[3]->parent = nodes[1] ; 
     nodes[1]->right = nodes[4] ; nodes[4]->parent = nodes[1] ; 

    nodes[2]->left = nodes[5] ;  nodes[5]->parent = nodes[2] ; 
    nodes[2]->right = nodes[6] ;  nodes[6]->parent = nodes[2] ; 

	nodes[4]->right = nodes[7] ; nodes[7]->parent = nodes[4] ; 
 	nodes[6]->right = nodes[8] ; nodes[8]->parent = nodes[6] ;  
 	
 	nodes[7]->left = nodes[9] ;  nodes[9]->parent = nodes[7] ; 
 	
    computeWidth(nodes[0]);   
    printTree(nodes[0]);
    system("PAUSE");
}









