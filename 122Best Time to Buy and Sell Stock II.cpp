/*
122. Best Time to Buy and Sell Stock II My Submissions QuestionEditorial Solution
Total Accepted: 88439 Total Submissions: 207457 Difficulty: Medium
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Subscribe to see which companies asked this question

*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0)return 0;
        int m = prices.size();
        int ans = 0;
        for(int i = 1;i<m;++i)
        {
            if(prices[i]>prices[i-1])
            {
                ans+=prices[i]-prices[i-1];
            }
        }
        
        return ans;
    }
};