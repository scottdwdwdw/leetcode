/*
349. Intersection of Two Arrays My Submissions QuestionEditorial Solution
Total Accepted: 8422 Total Submissions: 18538 Difficulty: Easy
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.
Subscribe to see which companies asked this question

*/



class Solution {
public:
    //计算数组2与数组1重叠的部分
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ret;
        set<int>first_nums(nums1.begin(),nums1.end());
        set<int>second_nums(nums2.begin(),nums2.end());
        
        for(auto it = first_nums.begin();it!=first_nums.end();++it)
        {
            if(second_nums.find(*it)!=second_nums.end())
            {
                ret.push_back(*it);
            }
        }
        return ret;
    }
};