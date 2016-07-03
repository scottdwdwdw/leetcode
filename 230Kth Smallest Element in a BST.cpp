/*
230. Kth Smallest Element in a BST My Submissions QuestionEditorial Solution
Total Accepted: 52484 Total Submissions: 135467 Difficulty: Medium
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

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
// 计算root的左子树有多少元素 count
//如果count+1==k,则root元素是我们要找的
//如果count>k，那么要找到的元素在左子树
//如果count<k,那么要找到的元素在右子树

//最基本的，找到最小值的节点，然后再找到第k小的元素，时间复杂度是o(n)
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
            TreeNode*right = node_temp->right;   //向左
            while(right!=NULL)
            {
                val.push_back(right);
                right = right->left;
            }
        }
       
        return -1;
   
    }
};