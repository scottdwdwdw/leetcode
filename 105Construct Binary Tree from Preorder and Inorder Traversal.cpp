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
    //һ���� �磺
    //      A
    //      /\
    //     B  C
    //    /\
    //    D E
    //ǰ�������ABDEC   �������:DBEAC
    //��ǰ���������ȷ�������������������ȷ����Щ������������Щ��������
    //ʹ�õݹ鷽��(���ظ�Ԫ��)
    
  
    
    TreeNode* buildTree_dispatch(int Pstart,int Pend,int Istart,int IEnd,vector<int>&preorder,vector<int>&inorder)
    {
        
        //�˳�����
        if(IEnd<Istart)return NULL;  //������
        
        //�����½ڵ�
        TreeNode*node = new TreeNode(-1);
        node->val = preorder[Pstart];

        
        //������Ӧֵ����������е�λ��
        int pos;
        for(pos=Istart;pos<IEnd;++pos)  
        {
            if(inorder[pos]==preorder[Pstart])break;
        }
        
        //������һ��ǰ���������������������±�
        int offset = pos-Istart;  //ע�����������
        //ǰ������±�
        int leftPStart = Pstart+1;
        int leftPEnd = Pstart+offset;  //�Ǽ���һ�����ƫ��������Ҫֱ�Ӽ���pos,��������������±겻�ԡ�
     
        //��������±�
        int IleftStart = Istart;
        int IleftEnd = pos-1;
       
        
        //��������ĵط���ǰ��������±�ȷ��
        
        //�ݹ�
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
