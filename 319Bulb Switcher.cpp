/*
319. Bulb Switcher My Submissions QuestionEditorial Solution
Total Accepted: 20829 Total Submissions: 50669 Difficulty: Medium
There are n bulbs that are initially off. You first turn on all the bulbs. Then, you turn off every second bulb. On the third round, you toggle every third bulb (turning on if it's off or turning off if it's on). For the ith round, you toggle every i bulb. For the nth round, you only toggle the last bulb. Find how many bulbs are on after n rounds.

Example:

Given n = 3. 

At first, the three bulbs are [off, off, off].
After first round, the three bulbs are [on, on, on].
After second round, the three bulbs are [on, off, on].
After third round, the three bulbs are [on, off, off]. 

So you should return 1, because there is only one bulb is on.
*/


class Solution {
public:
    /*
    //o(n^2)复杂度
    //会超时,计算9999999时会超时
    int bulbSwitch(int n) {
        int k = 1;
        vector<int>bulbs(n,1);
        for(int i=1;i<n;++i)
        {
            for(int k=i;k<n;k=k+i+1)
            {
                bulbs[k]=(bulbs[k]==1?0:1);
            }
        }
        
        //完成
        int res = 0;
        for(int l=0;l<n;++l)
        {
            res+=bulbs[l];
        }
        
        return res;
        
    }*/
    
   // http://blog.csdn.net/baidu_23318869/article/details/50386323
   //由该提示，知道，最后演变为求取小于n的数有多少个数是完全平方数
    int bulbSwitch(int n) {
        int res=0;
        for(int i=1;i*i<=n;++i)
        {
           ++res;
        }
        return res;
    }
};


