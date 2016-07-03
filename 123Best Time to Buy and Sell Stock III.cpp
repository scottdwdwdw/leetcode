/*
123. Best Time to Buy and Sell Stock III My Submissions QuestionEditorial Solution
Total Accepted 57870 Total Submissions 218269 Difficulty Hard
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Subscribe to see which companies asked this question

Show Tags
Show Similar Problems
*/

class Solution {
public:
    //分成两部分,以第i天为分界线，max profit = max(preProfit+postProfit);
    //第一次正向扫描，求得第一次交易能达到的最大值
    //第二次逆向扫描，求得第二次交易能达到的最大值
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2)return 0;
        int m = prices.size();
        int lowest_prices = prices[0];
        int first_case = 0;
        int second_case = 0;
        vector<int>preProfit(prices.size(),0);
        vector<int>secProfit(prices.size(),0);
        //第一天的交易
        for(int i=1;i<m;++i)
        {
            if(prices[i]<lowest_prices)
            {
                lowest_prices = prices[i];
            }
            else if(first_case<prices[i]-lowest_prices)
            {
                first_case = prices[i]-lowest_prices;
            }
            preProfit[i] = first_case;
        }
        
        int max_price = prices[m-1];
        //逆向扫描,第二天的交易
        for(int i=m-2;i>=0;--i)
        {
            if(prices[i]>max_price)
            {
                max_price = prices[i];
            }
            else if(second_case<max_price-prices[i])
            {
                second_case = max_price-prices[i];
            }
            secProfit[i]=second_case;
        }
        
        //找到最大值
        int ret_ans=0;
        int temp;
        for(int i=0;i<m;++i)
        {
           temp = preProfit[i]+secProfit[i];
           if(temp>ret_ans)ret_ans = temp;
        }
        
        return ret_ans;
    }
};
