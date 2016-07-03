
/*
75. Sort Colors   My Submissions QuestionEditorial Solution
Total Accepted: 97364 Total Submissions: 280340 Difficulty: Medium
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

*/


//1.使用插入排序

class Solution {
public:
    void insert_sort(vector<int>&nums)
    {
        for(int i=1;i<nums.size();++i)
        {
            if(nums[i]<nums[i-1])
            {
                int num_save = nums[i];
                int j = i-1;
                for(;j>=0&&nums[j]>num_save;--j)//找到插入位置
                {
                   nums[j+1] = nums[j];
                }
                nums[j+1] = num_save;
            }
        }
    }
    void sortColors(vector<int>& nums) {
       if(nums.size()>=1)
       {
           insert_sort(nums);
       }
    }
};

//2.使用快排