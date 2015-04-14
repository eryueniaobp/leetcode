#include <iostream>
#include <stack> 
#include <cstdlib>
#include <string> 
#include <vector>
using namespace std;
/** 
* HINT: 
*     The most valuable solution is iterative way without *visitNum* . See the solutions at the end of the file 
*/
class TreeNode {
public:
	TreeNode *left;
	TreeNode *right ; 
	int data; 
	int visitNum ; 
public :
	TreeNode() {
		visitNum = 0 ;
		left = NULL;
		right = NULL ; 
	}
	TreeNode(int data){
		this->data = data ;
		left = NULL ;
		right = NULL ; 
		visitNum = 0 ;
	}
};
void visit(TreeNode *root) {
	// todo 
	cout<< root->data <<"\t";
}
//stack<TreeNode* > nodes;  
//void push(TreeNode * node) {
//	nodes.push(node);
//	cout<<node->data<<endl;
//} 
void postOrderRecursive(TreeNode *root)
{
	if(root == NULL ) return;
    postOrderRecursive(root->left)  ; 
    postOrderRecursive (root->right) ; 
    visit(root);
}
void preOrderRecursive(TreeNode *root)
{
	if(root == NULL ) return; 
	visit(root);
	preOrderRecursive(root->left ) ;
	preOrderRecursive(root->right ) ;
}
void middleOrderRecursive(TreeNode *root)
{
	if(root == NULL ) return ;
	middleOrderRecursive(root->left ) ; 
	visit(root) ;
	middleOrderRecursive(root->right ) ; 
}
void middleOrder(TreeNode *root)
{
	if(root==NULL) return; 
	stack<TreeNode* > nodes; 
	nodes.push(root) ; 
	while(!nodes.empty()){
		TreeNode * cur = nodes.top() ; 
		if(cur->visitNum == 0 ) {
			
			cur->visitNum ++ ; 
			if(cur->left != NULL ) {
				nodes.push(cur->left) ;
			}
		}else if(cur->visitNum == 1 ) {
			visit(cur);  //  这个 visit 位置，决定了是 pre,middle ,post order . 
			cur->visitNum ++ ; 
			if( cur->right != NULL ){
				nodes.push(cur->right) ;
			}
		}else{
			nodes.pop();
		}
		
	}
}
//@deprecated see the solution in end of the file
void preOrder(TreeNode *root) 
{
	if(root == NULL ) return; 
	
	stack<TreeNode* > nodes; 
	nodes.push(root) ; 
	while(!nodes.empty()){
		TreeNode * cur = nodes.top() ; 
		if(cur->visitNum == 0 ) {
			visit(cur) ;
			cur->visitNum ++ ; 
			if(cur->left != NULL ) {
				nodes.push(cur->left) ;
			}
		}else if(cur->visitNum == 1 ) {
			cur->visitNum ++ ; 
			if( cur->right != NULL ){
				nodes.push(cur->right) ;
			}
		}else{
			nodes.pop();
		}
		
	}
}
void postOrder(TreeNode *root) 
{
	stack<TreeNode* > nodes;  
	nodes.push(root) ; 
	
	while( !nodes.empty() ) {
		TreeNode * cur = nodes.top(); 
		if(cur->visitNum == 0 ) {
			cur->visitNum ++ ;
			cur = cur->left ;
			if( cur != NULL )    nodes.push(cur) ;
		}else if( cur->visitNum == 1 ) {
			cur->visitNum ++ ; 
			cur= cur ->right ;
			if( cur != NULL )  nodes.push (cur) ;
		}else {
			visit(cur) ;
			nodes.pop();
		}
	}
	
}
void clear(vector<TreeNode* > &nodes ) 
{
	for(int i = 0 ;i <nodes.size() ; i ++ ){
		nodes[i]->visitNum = 0 ;
	}
}
int main(int argc, char * argv[])
{
	vector<TreeNode* > nodes  ; 
	for(int i = 0 ; i< 8 ; i++ ) {
		TreeNode * node = new TreeNode(i+1); 
		nodes.push_back(node);
	}
	for(int i = 0 ;i< 8 ; i++){
		cout<< nodes[i]->data << " " ;
	}
	cout<<endl;
	nodes[0]->left = nodes[1] ; 
	nodes[0]->right = nodes[2] ; 

	nodes[1]->left = nodes[3] ; 
	nodes[1]->right = nodes[4] ;

	nodes[3]->left = nodes[5] ; 
	nodes[3]->right = nodes[6] ; 

	nodes[4]->right = nodes[7] ;
	cout<<"Post Order: "<<endl;
	postOrder(nodes[0]); 
	clear(nodes); 
	cout<<endl;


	cout<<"Recursively "<<endl; 
    postOrderRecursive(nodes[0]);
	clear(nodes);
	cout<<endl;

	cout<<"Pre Order: "<<endl;
	preOrder(nodes[0]);
	clear(nodes);	
	cout<<endl;

	cout<<"Recursively "<<endl; 
    preOrderRecursive(nodes[0]);
	clear(nodes);
	cout<<endl;

	cout<<"Middle Order" <<endl; 
	middleOrder(nodes[0]);
	clear(nodes);
	cout<<endl;

	cout<<"Recursively "<<endl; 
	middleOrderRecursive(nodes[0]);
	clear(nodes);
	cout<<endl;

	return 0;
}

/**  
两种不需要 额外定义 visitNum的方法
postOrder必须要专门的visitNum方法
void inOrder2(BinTree *root)      //非递归中序遍历
{
    stack<BinTree*> s;
    BinTree *p=root;
    while(p!=NULL||!s.empty())
    {
        while(p!=NULL)
        {
            s.push(p);
            p=p->lchild;
        }
        if(!s.empty())
        {
            p=s.top();
            cout<<p->data<<" ";  // 这里区分是 pre还是 middle.
            s.pop();
            p=p->rchild;
        }
    }    
}

void preOrder2(BinTree *root)     //非递归前序遍历
{
    stack<BinTree*> s;
    BinTree *p=root;
    while(p!=NULL||!s.empty())
    {
        while(p!=NULL)
        {
            cout<<p->data<<" ";
            s.push(p);
            p=p->lchild;
        }
        if(!s.empty())
        {
            p=s.top();
            s.pop();
            p=p->rchild;
        }
    }
}
**/
/*****************************************************************/
// Java Solution 
 //Another Clear Solution for traverse!  Just one while ,more elegant 
    public void traverse(TreeNode root) {
        if (root == null) return;
        Stack<TreeNode> st = new Stack<TreeNode>();
        TreeNode n = root;
        while (true) {
            if (n != null) {
                //System.out.println(n.val); //  PRE-ORDER 
                st.push(n);
                n = n.left;
            } else {
                if (!st.isEmpty()) {
                    n = st.pop();
                    //System.out.println(n.val); //  IN-ORDER 
                    n = n.right;
                } else {
                    break;
                }
            }
        }
    }

