/*
34. Search for a Range My Submissions QuestionEditorial Solution
Total Accepted: 83419 Total Submissions: 284967 Difficulty: Medium
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

//采用二分查找法，复杂度log(n)

class Solution {
public:
    vector<int> binarySearch(int left,int right,vector<int>&nums,int target)
    {
        vector<int>ret(2,-1);
        while(left<=right)  //nums 是已经排好序的数组。
        {
            int mid = left+(right-left)/2 ;  
            if(nums[mid]<target)
            {
                left = mid+1;
            }
            else if(nums[mid]>target)
            {
                right = mid-1;
            }
            else  //nums[mid] == target
            {
                int find_position = mid;
                int left_position = find_position;
                int right_position = find_position;
                while(left_position>=0&&nums[left_position] == target)--left_position;
                while(right_position<nums.size()&&nums[right_position]==target)++right_position;
                ret[0] = left_position+1;
                ret[1] = right_position-1;
                
                return ret;
            }
        }
        return ret;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return binarySearch(0,nums.size()-1,nums,target);
    }