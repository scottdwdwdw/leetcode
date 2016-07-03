/*
136. Single Number My Submissions QuestionEditorial Solution
Total Accepted: 130779 Total Submissions: 260625 Difficulty: Medium
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Subscribe to see which companies asked this question
*/


//��ʵ�������ǿ�����λ������һ�������Լ������0
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i=0;i<n;++i)
        {
            sum = sum^nums[i];
        }
        return sum;
    }
};