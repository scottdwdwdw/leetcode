/*
105. Construct Binary Tree from Preorder and Inorder Traversal My Submissions QuestionEditorial Solution
Total Accepted: 64242 Total Submissions: 222588 Difficulty: Medium
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

Subscribe to see which companies asked this question

Show Tags
Show Similar Problems
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //一颗树 如：
    //      A
    //      /\
    //     B  C
    //    /\
    //    D E
    //前序遍历：ABDEC   中序遍历:DBEAC
    //由前序遍历可以确定根，右中序遍历可以确定哪些是左子树，哪些是右子树
    //使用递归方法(无重复元素)
    
  
    
    TreeNode* buildTree_dispatch(int Pstart,int Pend,int Istart,int IEnd,vector<int>&preorder,vector<int>&inorder)
    {
        
        //退出条件
        if(IEnd<Istart)return NULL;  //左子树
        
        //创建新节点
        TreeNode*node = new TreeNode(-1);
        node->val = preorder[Pstart];

        
        //查找相应值在中序遍历中的位置
        int pos;
        for(pos=Istart;pos<IEnd;++pos)  
        {
            if(inorder[pos]==preorder[Pstart])break;
        }
        
        //计算下一次前序遍历，中序遍历的数组下标
        int offset = pos-Istart;  //注意这里，，，，
        //前序遍历下标
        int leftPStart = Pstart+1;
        int leftPEnd = Pstart+offset;  //是加上一个相对偏移量，不要直接加上pos,这样计算出来的下标不对。
     
        //中序遍历下标
        int IleftStart = Istart;
        int IleftEnd = pos-1;
       
        
        //出现问题的地方在前序遍历的下标确定
        
        //递归
        node->left = buildTree_dispatch(leftPStart,leftPEnd,IleftStart,IleftEnd,preorder,inorder); //left
        int rightPStart = leftPEnd+1;
        int rightPEnd = Pend;
         //
        int IrightStart = pos+1;
        int IrightEnd = IEnd;
      //  if(IrightStart>IrightEnd)return node;
        node->right = buildTree_dispatch(rightPStart,rightPEnd,IrightStart,IrightEnd,preorder,inorder); //right
        
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0)return NULL;
        return buildTree_dispatch(0,preorder.size()-1,0,preorder.size()-1,preorder,inorder);
    }
};
