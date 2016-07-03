/*
121. Best Time to Buy and Sell Stock My Submissions QuestionEditorial Solution
Total Accepted: 103538 Total Submissions: 285766 Difficulty: Easy
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Subscribe to see which companies asked this question

Show Tags
Show Similar Problems

*/
//这个题的题意不太好理解。。。。
class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0)return 0;
        int ans = -65535;
        int n = prices.size();
        int lowest_price = prices[0];
        for(int i = 0;i<n;++i)
        {
            if(prices[i]<lowest_price)lowest_price = prices[i];
            else if(ans<prices[i]-lowest_price)ans = prices[i]-lowest_price;
        }
       
        
        return ans;
    }
};
