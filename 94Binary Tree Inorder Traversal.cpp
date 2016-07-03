

/*

 94. Binary Tree Inorder Traversal My Submissions QuestionEditorial Solution
Total Accepted: 127083 Total Submissions: 317588 Difficulty: Medium
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].
 
 */
 /* Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    //�����ı������õ����ķ�ʽ����
    //����1���ݹ鷽��
    void inorderTraversal_dispatch(TreeNode* Node,vector<int>&res)
    {
        if(Node==NULL)
        {
            return;
        }
        inorderTraversal_dispatch(Node->left,res); //����
        res.push_back(Node->val);
        inorderTraversal_dispatch(Node->right,res); //����
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>res;
        if(root==NULL)return res;
        inorderTraversal_dispatch(root->left,res);
        res.push_back(root->val);
        inorderTraversal_dispatch(root->right,res);
        return res;
    }
	
	
	 //����2���õ����ķ���
   // ����1�� ����������ֱ������ΪNULL,�ڴ˹����У��ѽڵ�ֵ��ջ
   // ����2:  �������ΪNULL,����һ���ڵ�����������У�����ջ�ҽڵ�(����еĻ�)��ת������1
   // ����3�� ����Һ���ͬ��ҲΪNULL,�����ڵ㣬ת����2
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int>res;
        if(root==NULL)return res;
        vector<TreeNode*>st;
        st.push_back(root);
        TreeNode*temp = root->left;
        while(st.size()!=0||temp!=NULL)
        {
            if(temp!=NULL) //���Ӳ�Ϊ��
            {
                st.push_back(temp);
                temp = temp->left;
            }
            else 
            {
                res.push_back(st.back()->val);   //����ڵ������������
                temp = st.back()->right;
                st.pop_back();   //��ջ
            }
            
        }
        
        return res;
    }
};


