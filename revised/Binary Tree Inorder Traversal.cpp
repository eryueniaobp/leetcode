/** 
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct Node
{
    TreeNode *tNode;
    bool findLeft;
    Node(){}
    Node(TreeNode *n,bool fl):tNode(n), findLeft(fl){}
};

class Solution {
private:
    vector<int> ret;
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<Node> s;
        s.push(Node(root, false));
        ret.clear();
        
        while(!s.empty())
        {
            Node node = s.top();
            if (node.tNode == NULL)
                s.pop();
            else
            {
                if (!node.findLeft)
                {
                    s.pop();
                    s.push(Node(node.tNode, true));
                    s.push(Node(node.tNode->left, false));
                }
                else
                {
                    s.pop();
                    ret.push_back(node.tNode->val);
                    s.push(Node(node.tNode->right, false));
                }
            }
        }
        
        return ret;
    }
};

