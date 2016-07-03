/*
96. Unique Binary Search Trees My Submissions QuestionEditorial Solution
Total Accepted: 87439 Total Submissions: 230074 Difficulty: Medium
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
 */  
   
class Solution {
public:
    //算法复杂度:o(n^2)
    //动态规划:
    // 当n=1 时，dp[1]=1；
    // n=2,      dp[2]=2;
    // n = 3,    dp[3]=2+1+2=5;
    // n = 4,    dp[4]=dp[1]+(dp[2]+dp[4-2-1])+(dp[3]+dp[4-3-1]) = 
    // n = 5,    dp[5]=(dp[0]+dp[5-1-0])+(dp[1]+dp[5-1-1])+(dp[2]+dp[5-2-1])+(dp[3]+dp[5-1-3])+(dp[4]+dp[5-1-4])=
    int numTrees(int n) {
        vector<int>dp(n+1,0);
        dp[0]=0;
        dp[1]=1;
        for(int i = 2;i<=n;++i)
        {
            for(int j = 0;j<i;++j)//i-j-1表示右边的元素个数
            {
                int n1 = dp[j];
                int n2 = dp[i-j-1];
                if(n2==0)n2=1;
                if(n1==0)n1=1;
                
                dp[i]+=n1*n2;
            }
        }
        
        return dp[n];
    }
};