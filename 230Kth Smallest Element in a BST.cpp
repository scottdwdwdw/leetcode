/*
230. Kth Smallest Element in a BST My Submissions QuestionEditorial Solution
Total Accepted: 52484 Total Submissions: 135467 Difficulty: Medium
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 �� k �� BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

Show Hint
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
// ����root���������ж���Ԫ�� count
//���count+1==k,��rootԪ��������Ҫ�ҵ�
//���count>k����ôҪ�ҵ���Ԫ����������
//���count<k,��ôҪ�ҵ���Ԫ����������

//������ģ��ҵ���Сֵ�Ľڵ㣬Ȼ�����ҵ���kС��Ԫ�أ�ʱ�临�Ӷ���o(n)
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<TreeNode*>val;
        while(root!=NULL)
        {
            val.push_back(root);
            root=root->left;
        }
        int n=0;
        while(val.size()&&n<=k)
        {
            auto node_temp = val.back();
            val.pop_back();
            ++n;
            if(n==k)return node_temp->val;
            TreeNode*right = node_temp->right;   //����
            while(right!=NULL)
            {
                val.push_back(right);
                right = right->left;
            }
        }
       
        return -1;
   
    }
};