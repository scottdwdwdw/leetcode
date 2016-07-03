/*
268. Missing Number   My Submissions QuestionEditorial Solution
Total Accepted: 50420 Total Submissions: 125268 Difficulty: Medium
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.
*/

//相见法
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if(nums.size()==0)return 0;
        int n=nums.size();
        int desire_n = n+1;
        int sum = (desire_n*desire_n-desire_n)>>1;
        int sum_temp = 0;
        for(size_t i=0;i<n;++i)
        {
            sum_temp+=nums[i];
        }
        return sum-sum_temp;
    }
};
//位操作
class Solution {
public:
    int missingNumber(vector<int>& nums) {
           int res=0;
           for (int i=0;i<nums.size();i++)
           {
               res^=nums[i]^i;   //如果nums[i]不缺，那么nums[i]^i 的值就是0
           }
          res^=nums.size();
          return res;
    }
};