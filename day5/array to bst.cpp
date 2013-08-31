#include <cstdlib>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
#include <map>
using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return makeTree(num,0,num.size());
    }
    TreeNode *makeTree(vector<int> &num,int s,int e){
        if(s>=e) {
            return NULL;                      
        }
        int pos = (s+e)/2;
        TreeNode *node = new TreeNode(num[pos]);
        node->left = makeTree(num,s,pos);
        node->right = makeTree(num,pos+1,e);
        return node;
    }
};









int main(int argc, char *argv[])
{
    Solution *a = new Solution();
    int ar[] = {1,2,3,4,5,6,7,8,9,10};
    a->sortedArrayToBST(vector<int>(ar,ar+10));
    system("PAUSE");
    return EXIT_SUCCESS;
}



