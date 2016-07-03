/*
64. Minimum Path Sum My Submissions QuestionEditorial Solution
Total Accepted: 71323 Total Submissions: 203755 Difficulty: Medium
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Subscribe to see which companies asked this question

*/


class Solution {
public:
   //使用动态规划
   //从起点到(i,j)的路径和，sum[i][j] = min(sum[i-1][j],sum[i][j-1])
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        //计算行的和
        for(int i=1;i<n;++i)
        {
            grid[0][i]=grid[0][i]+grid[0][i-1];
        }
        for(int j=1;j<m;++j)
        {
            grid[j][0] = grid[j-1][0]+grid[j][0];
        }
        //
        for(int i=1;i<m;++i)
        {
            for(int j=1;j<n;++j)
            {
                if(grid[i-1][j]<grid[i][j-1])grid[i][j]+=grid[i-1][j];
                else if(grid[i-1][j]>=grid[i][j-1])
                {
                    grid[i][j] += grid[i][j-1];
                }
            }
        }
        
        return grid[m-1][n-1];
        
    }
};