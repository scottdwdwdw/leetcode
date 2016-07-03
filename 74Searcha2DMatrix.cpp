/*
74. Search a 2D Matrix My Submissions QuestionEditorial Solution
Total Accepted: 79710 Total Submissions: 234697 Difficulty: Medium
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*/


//搜索给定的值，判断是否在该矩阵中
//
//方法一，直接遍历
//时间复杂度是o(m*n)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();   //行
        int n = matrix[0].size(); //列
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(matrix[i][j]==target)return true;
            }
        }
        
        return false;
    }
};

//根据提示，用二分查找做
class Solution {
public:
    int binarySearch(int left,int right,int target,vector<int>& line)
    {
        int mid;
        while(left<=right)
        {
            mid = left+(right-left)/2;
            if(line[mid]>target)//目标值在左半边
            {
                right = mid-1;
            }
            else if(line[mid]<target)//目标值在右半边
            {
                left = mid+1;
            }
            else  //找到该值
            {
                return mid;
            }
        }
        
        //该值不在矩阵中
        if(right<0)return -1;  
        //目标值有可能在最后一行中
        if(left>=line.size())return line.size()-1;
        //该值在合法范围内
        return line[left]>target?right:left;
    }
    
   
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       //由于数组是有序的，所以，先确定该数所在的行
       int m = matrix.size();
       int n = matrix[0].size();
       vector<int>row(m,0);
       for(int i=0;i<m;++i)row[i]=matrix[i][0];   //第一列
       //确定所在行
       int row_num = binarySearch(0,m-1,target,row);
       if(row_num<0)return false;
       else if(matrix[row_num][0]==target)return true; 
       //寻找目标值
       int col_num = binarySearch(0,n-1,target,matrix[row_num]);
       
       if(matrix[row_num][col_num]!=target)return false;
       else 
       {
           return true;
       }
        
    }
};