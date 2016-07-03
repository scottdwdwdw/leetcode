/*
120. Triangle My Submissions QuestionEditorial Solution
Total Accepted: 70339 Total Submissions: 231825 Difficulty: Medium
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
*/

//

class Solution {
public:
   //动态规划
   //题意理解错了，只能是下一行相邻的数
   //自低向上
   //公式： triangle[i][j] = min(triangle[i][j]+triangle[i+1][j],triangle[i][j]+triange[i+1][j+1])
    int minimumTotal(vector<vector<int>>& triangle) {
         int m = triangle.size();  //行
         for(int i = m-2;i>=0;--i)
         {
             int n = triangle[i].size();
             for(int j=0;j<n;++j)
             {
                 int temp1 = triangle[i][j]+triangle[i+1][j];
                 int temp2 = triangle[i][j]+triangle[i+1][j+1];
                 triangle[i][j] = temp1>temp2?temp2:temp1;
             }
         }
         
         return triangle[0][0];
    }
};