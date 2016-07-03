240. Search a 2D Matrix II My Submissions QuestionEditorial Solution
Total Accepted: 39602 Total Submissions: 113228 Difficulty: Medium
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
For example,

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.

class Solution {
public:
   //对整个矩阵是divide and conquer
   //对矩阵的每一行都使用二分查找
   //我这道题只用到了二分查找法
   bool binarySearch(vector<int>&data,int target)
   {
       int left = 0;
       int right = data.size()-1;
       while(left<=right)
       {
           int mid = left+(right-left)/2;
           if(data[mid]<target)left=mid+1;
           else if(data[mid]>target)right=mid-1;
           else
           {
               return true;
           }
       }
       
       return false;
   }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        for(int i = 0;i<m;++i)
        {
            auto res = binarySearch(matrix[i],target);
            if(res==true)return res;
        }
        
        return false;
    }
};