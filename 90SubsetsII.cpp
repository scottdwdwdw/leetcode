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
    //��������
    void brute_search(int start,vector<int>&res_copy,vector<vector<int>>&ret,vector<int>&nums)
    {
        for(int i=start;i<nums.size();)
        {
            start = i;
            res_copy.push_back(nums[i]);  //Ԫ����ջ
            brute_search(start+1,res_copy,ret,nums);
           
            ++i;
            if(i>0&&i<nums.size()&&nums[i-1]==nums[i])
            {
                while(nums[i-1]==nums[i])++i;
            }
        }
        //������ͷ��������
        vector<int>res = res_copy;
        sort(res.begin(),res.end()); //����
        ret.push_back(res);
        //��ջ
        res_copy.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());   //������
        vector<vector<int>>ret;
        vector<int>res_copy;
        brute_search(0,res_copy,ret,nums);
        return ret;
    }
};