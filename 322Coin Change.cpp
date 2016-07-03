/*
322. Coin Change My Submissions QuestionEditorial Solution
Total Accepted: 26935 Total Submissions: 106614 Difficulty: Medium
You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:
coins = [1, 2, 5], amount = 11
return 3 (11 = 5 + 5 + 1)
*/
class Solution {
public:
    //��̬�滮�ĵ�����Ŀ
    //�����ǳ�ʱ
    int coinChange(vector<int>& coins, int amount) {
        if(coins.size()==0)return -1;
        else if(amount == 0)return 0;
        vector<int>dp(amount+1,32767);
        /*
        for(auto&e:coins)
        {
            if(e>amount)continue;
            dp[e] = 1;
        }
        */
        dp[0] = 0;
        
        for(int i = 1;i<=amount;++i)
        {
            for(int j = 0;j<coins.size();++j)
            {
                if(coins[j]<=i)
                {
                   dp[i] = min(dp[i-coins[j]]+1,dp[i]);
                }
                
            }
        }
        
        int res=0;
        if(dp[amount]==32767)res = -1;
        else
        {
            res = dp[amount];
        }
        
        return res;
        
    }
};