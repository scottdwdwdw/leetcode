/*
90. Subsets II My Submissions QuestionEditorial Solution
Total Accepted: 68197 Total Submissions: 221542 Difficulty: Medium
Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

class Solution {
public:
    //暴力搜索
    void brute_search(int start,vector<int>&res_copy,vector<vector<int>>&ret,vector<int>&nums)
    {
        for(int i=start;i<nums.size();)
        {
            start = i;
            res_copy.push_back(nums[i]);  //元素入栈
            brute_search(start+1,res_copy,ret,nums);
           
            ++i;
            if(i>0&&i<nums.size()&&nums[i-1]==nums[i])
            {
                while(nums[i-1]==nums[i])++i;
            }
        }
        //搜索到头，保存结果
        vector<int>res = res_copy;
        sort(res.begin(),res.end()); //排序
        ret.push_back(res);
        //出栈
        res_copy.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());   //先排序
        vector<vector<int>>ret;
        vector<int>res_copy;
        brute_search(0,res_copy,ret,nums);
        return ret;
    }
};