/**
 * 给每一个元素标号 即可 
 * 如果是完全二叉树，那么标号与节点个数是对应的，不然的话，肯定标号与节点个数不一致
 */
int maxId = 0 ; 
int nodeNum = 0 ;
bool isComBinTree(Node *root){
    dfs(root , 0 ) ;
    return maxId +1 == nodeNum ;
}
void dfs(Node *root,int id){
    if(root == NULL ) return; 
    nodeNum++;
    maxId = max(id,maxId) ;
    dfs(root->left,2*id+1);
    dfs(root->right,2*id+2) ;
}
