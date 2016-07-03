/*
70. Climbing Stairs My Submissions QuestionEditorial Solution
Total Accepted: 115252 Total Submissions: 309959 Difficulty: Easy
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Subscribe to see which companies asked this question
*/

class Solution {
public:
    //每次加1或加2,问有多少种加法，使总和为n
    // num[i] = num[i-1]+1或则num[i-2]+2;
    // o(n)
    int climbStairs(int n) {
        //有n步
        //n = 1时, dp[1] = 1;
        //n = 2 ,  dp[2] = 2;
        //n = 3 , dp[3] = dp[2]+dp[1] = 3
        //n = 4,  dp[4] = dp[3]+dp[2] = 5
        //n = 5,  dp[5] = dp[4]+dp[3] = 8
        if(n==0)return 0;
        else if(n==1)return 1;
        else if(n==2)return 2;
        vector<int>dp(n);
        dp[0]=1;
        dp[1]=2;
        for(int i=2;i<n;++i)
        {
            dp[i] = dp[i-1]+dp[i-2];
        }
        
        return dp[n-1];
    }
};