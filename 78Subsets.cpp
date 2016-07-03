/*
78. Subsets My Submissions QuestionEditorial Solution
Total Accepted: 96434 Total Submissions: 304869 Difficulty: Medium
Given a set of distinct integers, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

*/

//
class Solution {
public:
    //使用回溯法/深度搜索
    void DFS(int start,vector<int>&nums,vector<int>&signle_res,vector<vector<int>>&res)
    {
        for(int i=start;i<nums.size();++i)
        {
            signle_res.push_back(nums[i]);   //入栈
            DFS(i+1,nums,signle_res,res);   //递归调用
            signle_res.pop_back();          //弹出
        }
        //若start>=nums.size(),执行到此,将结果存入数组中
        vector<int>res_copy = signle_res;
        sort(res_copy.begin(),res_copy.end());
        res.push_back(res_copy);    
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int>signle_res;
        vector<vector<int>>res;
        DFS(0,nums,signle_res,res);
        
        return res;
    }
};