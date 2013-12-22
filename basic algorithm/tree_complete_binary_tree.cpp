
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

bool isCompleteBinaryTree(TreeNode *root){
    if(root == NULL ) return false; 
    queue<TreeNode* > queue ; 
    root->visitId = 0 ;
    queue.push(root);
    TreeNode * temp = NULL ;
    int preId = -1 ; 
    while(!queue.empty()){
        temp = queue.front(); queue.pop(); 
        int pid = temp->visitId; 
        if( preId+1 != pid  ) {
            return false; 
        }else{
            preId++;
        }
        if(temp->left!=NULL){
            temp->left->visitId = 2*pid +1 ; 
            queue.push(temp->left) ; 
        }
        if(temp->right!=NULL){
            temp->right->visitId = 2*pid +2 ; 
            queue.push(temp->right);
        }
    }
    return true; 

}

int leftDepth(TreeNode * root) {
    if( root == NULL ) return 0 ; 
    int d = 0; 
    while (root != NULL ) {
        root = root->left;  
        d++ ;
    }
    return d; 
}
int rightDepth(TreeNode *root) {
    if(root == NULL ) return 0 ; 
    int d = 0 ; 
    while (root!= NULL ) {
        root = root->right ; 
        d++ ; 
    }
    return d ; 
}
// 向完全二叉树插入新节点 time-complex: (logn)^2 
void insertNodeToCompleteBinaryTree(TreeNode* root,TreeNode* node){
    if(root==NULL) return; 
    TreeNode * temp = NULL ; 
    while(leftDepth(root) != rightDepth(root)) {
        int l1 = leftDepth(root->left) ; 
        int r1 = rightDepth(root->left)  ; 
        // assert l1 > 0 && r1 > 0  
        if(l1 == r1 ) {
            if(leftDepth(root->right) ==  0) {
                root->right = node ;
                return ;
            }
            root = root->right;
        }else{
            //assert ( l2 == r2 )  
            root = root->left ; 
        }
    }
    while(root->left != NULL ) {
        root = root->left; 
    }
    root->left = node ; 
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
    nodes[2]->right = nodes[6] ;  nodes[6]->parent = nodes[2] ; 


 //	nodes[3]->left = nodes[7] ;  
    insertNodeToCompleteBinaryTree(nodes[0],nodes[7]) ; 
    cout<<"Insert Ok"<<endl;
    if(isCompleteBinaryTree(nodes[0])){
        cout<<"Is Complete!"<<endl;
    }else{
        cout<<"No Complete!"<<endl;
    }
    system("PAUSE");
}








