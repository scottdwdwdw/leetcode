

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
    
    //这道题的本意是用迭代的方式来做
    //方法1，递归方法
    void inorderTraversal_dispatch(TreeNode* Node,vector<int>&res)
    {
        if(Node==NULL)
        {
            return;
        }
        inorderTraversal_dispatch(Node->left,res); //往左
        res.push_back(Node->val);
        inorderTraversal_dispatch(Node->right,res); //往右
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>res;
        if(root==NULL)return res;
        inorderTraversal_dispatch(root->left,res);
        res.push_back(root->val);
        inorderTraversal_dispatch(root->right,res);
        return res;
    }
	
	
	 //方法2：用迭代的方法
   // 步骤1： 向左搜索，直到左孩子为NULL,在此过程中，把节点值入栈
   // 步骤2:  如果左孩子为NULL,弹出一个节点至结果数组中，并入栈右节点(如果有的话)，转到步骤1
   // 步骤3： 如果右孩子同样也为NULL,弹出节点，转步骤2
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int>res;
        if(root==NULL)return res;
        vector<TreeNode*>st;
        st.push_back(root);
        TreeNode*temp = root->left;
        while(st.size()!=0||temp!=NULL)
        {
            if(temp!=NULL) //左孩子不为零
            {
                st.push_back(temp);
                temp = temp->left;
            }
            else 
            {
                res.push_back(st.back()->val);   //将左节点存入结果数组中
                temp = st.back()->right;
                st.pop_back();   //出栈
            }
            
        }
        
        return res;
    }
};


