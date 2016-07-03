
/*
81. Search in Rotated Sorted Array II My Submissions QuestionEditorial Solution
Total Accepted: 63301 Total Submissions: 197721 Difficulty: Medium
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.

Subscribe to see which companies asked this question
*/

//测试用例[1,3,1,1],[2,2,2,0,0,1],[1,3,1,1,1]

class Solution {
public:
    //特殊的地方在于数组中包含重复元素
    int findRotatedPoint(int left,int right,vector<int>&nums)
    {
        int mid = -1;
        while(left<=right)
        {
            mid = left+(right-left)/2;
           
            if(nums[mid]==nums[left]&&nums[mid]==nums[right])  //头尾，中间相等
            {
                while(nums[left+1]>=nums[left]&&left<=right)++left;
                while(nums[right-1]<=nums[right]&&left<=right)--right;
            }
            else if(nums[mid]>nums[right]&&nums[left]!=nums[mid])
            {
                left = mid;
            }
            else if(nums[mid]<nums[left]&&nums[right]!=nums[mid])
            {
                right = mid;
            }
            else if(right-left==1&&nums[left]==nums[mid])
            {
                return mid;
            }
            else if(right-left==1&&nums[right]==nums[mid])
            {
                return mid-1;
            }
            else if(nums[left]==nums[mid]&&nums[right]!=nums[mid])
            {
                left=mid;
            }
            else if(nums[right]==nums[mid]&&nums[left]!=nums[mid])
            {
                right=mid;
            }
            else 
            {
                break;
            }
        }
        
        return 0;    //没有找到旋转点
    }

    bool binarySearch(int left,int right,int target,vector<int>&nums)
    {
        int mid = -1;
        while(left<=right)
        {
            mid = left+(right-left)/2;
            if(nums[mid]>target)
            {
                right = mid-1;
            }
            else if(nums[mid]<target)
            {
                left = mid+1;
            }
            else
            {
                return true;
            }
        }
        
        return false;
    }
    //同样的，使用二分查找，先找到旋转轴，再判断该数是否存在数组中
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==1)
        {
            if(nums[0]==target)return true;
            else return false;
        }
        int left = 0;
        int right = 0;
        int point = findRotatedPoint(0,n-1,nums);
        if(nums[0]<=target&&nums[point]>=target)
        {
            left = 0;
            right = point;
        }
        else if(nums[point+1]<=target&&nums[n-1]>=target)
        {
            left=point+1;
            right = n-1;
        }
        else 
        {
            return false;
        }
        return binarySearch(left,right,target,nums);
    }
};