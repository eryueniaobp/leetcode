/**
九章算法中有讲到， 对每个节点，找到离他最近且比它大的左右两个节点中较小的那个，作为他的父节点。

其中，找父节点： 用递增栈分别从左向右和从右向左扫描一次，对每个节点取栈顶元素即可。 在O（n）时间里就可以找到距离该节点最近的比他大的节点。 

http://blog.csdn.net/brandohero/article/details/41858463 
O(N) ..Really perfect solution
*/
class Solution{
public:
TreeNode* maxTree(vector<int> A){
    int n = A.size() ;
    TreeNode* nodes = new TreeNode[n];
    for(int i = 0 ; i<n ; i++){
        nodes[i] =TreeNode(A[i]) ;
    }

    stack<int> ss;
    vector<int> lp(n,-1), rp(n,-1) ;
    for(int i = 0 ; i< n ;i++){
        while(!ss.empty() && A[i] >A[ss.top()] ) {
            ss.pop();
        }
        if(!ss.empty()) {
            lp[i] = ss.top();
        }
        ss.push(i) ;
    }
    ss = stack<int>() ; 
    for(int i = n -1 ; i>=0 ; i--){
        while(!ss.empty() && A[i] >A[ss.top()] ) {
            ss.pop(); 
        }
        if(!ss.empty()) {
            rp[i] = ss.top(); 
        }
        ss.push(i) ;
    }
    //construct tree 
    TreeNode *root = NULL ; 
    for(int i = 0 ; i<n ;i ++){
        if(lp[i] >=0 && (rp[i] < 0 || A[rp[i] ] > A[lp[i]] )) {
            nodes[lp[i]].right = &nodes[i] ; 
        }else if(rp[i] >= 0 && (lp[i] < 0 || A[lp[i]] > A[rp[i]]) ) {
            nodes[rp[i]].left = &nodes[i] ; 
        }else{
            root = &nodes[i];
        }
    }
    return root; 
        
}
};
