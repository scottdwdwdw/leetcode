/*
62. Unique Paths My Submissions QuestionEditorial Solution
Total Accepted: 88307 Total Submissions: 242204 Difficulty: Medium
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 3 x 7 grid. How many possible unique paths are there?

*/

class Solution {
public:
    //动态规划
    //思路，数组s[i][j]保存的事从起点到点(i,j)的所有路径的总和，那么第一行，第一列的值都为1(因为只能往右或往下走)
    //其他情况  s[i][j] = s[i][j-1]+s[i-1][j];
    int uniquePaths(int m, int n) {
        int **s = new int*[m];
        for(int i=0;i<m;++i)
        {
            s[i] = new int[n]();
        }
        
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                s[i][j] = 1;
            }
        }
        
        for(int i=1;i<m;++i)
        {
            for(int j=1;j<n;++j)
            {
                s[i][j] =s[i-1][j]+s[i][j-1];
            }
        }
        
        return s[m-1][n-1];
    }
};