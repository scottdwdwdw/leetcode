/*
54. Spiral Matrix My Submissions QuestionEditorial Solution
Total Accepted: 59692 Total Submissions: 263418 Difficulty: Medium
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].

*/

//实际上是编程实现的难点，主要是边界条件的考虑
//如:
/*
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ],
 [10,11,12 ],
 [13,14,15 ]
]

[
 [ 1, 2, 3, 4, 5],
 [ 4, 5, 6, 7, 8],
 [ 7, 8, 9, 10,11]
]
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ret;
        if(matrix.size()<=0)return ret;
        int rowBegin = 0;
        int colBegin = 0;
        int colEnd = matrix[0].size();
        int rowEnd = matrix.size();
        int circle_count = 0;
        while(rowBegin<rowEnd&&colBegin<colEnd)
        {
            while(colBegin<colEnd)  //向右
            {
                ret.push_back(matrix[rowBegin][colBegin]);
                ++colBegin;
            }
            --colBegin;
            ++rowBegin;
            if(rowBegin>=rowEnd)break;  //如果向右之后，行不再满足条件，退出
            while(rowBegin<rowEnd) //向下
            {
                ret.push_back(matrix[rowBegin][colBegin]);
                ++rowBegin;
            }
            if(matrix.size()>1&&matrix[0].size()>1)
            {
                --rowBegin;
                --colBegin;
                colEnd=circle_count;    //计数
                if(colBegin<colEnd)break;   //条件不满足，退出
                while(colBegin>=colEnd) //向左
                {
                   ret.push_back(matrix[rowBegin][colBegin]);
                   --colBegin;
                }
                 ++colBegin;
                --rowBegin;
                rowEnd = circle_count;
                while(rowBegin>rowEnd)//向上
               {
                   ret.push_back(matrix[rowBegin][colBegin]);
                   --rowBegin;
               }
                ++rowBegin;
                ++colBegin;
                ++circle_count;
                rowEnd=matrix.size()-circle_count;
                colEnd=matrix[0].size()-circle_count;
            }
            
        }
        
        return ret;
    }
};