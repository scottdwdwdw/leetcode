
/*
198. House Robber My Submissions QuestionEditorial Solution
Total Accepted: 76283 Total Submissions: 217010 Difficulty: Easy
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the 
*/
class Solution {
public:
    //有限制的背包问题,背包容量不限，但是不能拿相邻的包
    //dp[i] = max(dp[i-2]+nums[i],dp[i-1]);
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0)return 0;
        else if(n==1)return nums[0];
        
        int * dp = new int[n];
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i=2;i<n;++i)
        {
            dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
        }
        
        return dp[n-1];
    }
};