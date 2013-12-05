G的旧题目: 　google group
给一个数组，要求根据数组建一个二叉树。 
二叉树的根节点等于数组中最大的元素，然后最大的数把数组分成两部分，左子树对应左边那 部分，右子树对应右边那部分。要求复杂度O(n)。（写码）  


解法：　
大概就是用栈吧，是一个单调递减的栈。
初始空，对于i，将栈内所有小于a[i]的数出栈，并让他们作为i的左子树（多个数的话，自然就是最大的作为i的左孩子，然后一直右孩子下去）
然后把a[i]加入栈
最后假设再加入一个非常大的数，把前面的全弹出来就好了

每个i进出栈一次，O(n)


    