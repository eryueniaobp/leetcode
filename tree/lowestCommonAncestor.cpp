/*
 * TODO: 
 * Binary Tree 
 *
 * General Tree  
 *
 * LCA -> RMQ   
 * http://www.cppblog.com/myjfm/archive/2011/05/12/146282.aspx
 */ 

// Binary Tree 
typedef struct lca
{
    int data;
    struct lca *left, *right;
} lca;

int LCA(lca *root, lca *a, lca *b, lca **result)
{
    int l, r;
    if (root == NULL)
        return 0;
    if ((l = LCA(root->left, a, b, result)) == 2) return 2;
    if ((r = LCA(root->right, a, b, result)) == 2) return 2;
    if (l + r == 2) { *result = root; return 2; }
    if (root == a || root == b) {
        if (l + r == 1) { *result = root; return 2; }
        return 1;
    }
    return l + r;
}


