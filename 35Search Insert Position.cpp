/*
35. Search Insert Position   My Submissions QuestionEditorial Solution
Total Accepted: 105500 Total Submissions: 281956 Difficulty: Medium
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/


//这道题实际上考擦的就是二分查找


class Solution {
public:
    int binarySearch(int left,int right,int target,vector<int>&nums)
    {
        while(left<=right)
        {
            int mid = left+(right-left)/2;
            if(target<nums[mid])
            {
                right = mid-1;
            }
            else if(target>nums[mid])
            {
                left = mid+1;
            }
            else   //找到
            {
                return mid;
            }
        }
        
        //not find 
        return left;
    }
    
    
    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(0,nums.size()-1,target,nums);
    }
};