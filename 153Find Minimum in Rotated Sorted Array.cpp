
/*
153. Find Minimum in Rotated Sorted Array   My Submissions QuestionEditorial Solution
Total Accepted: 91233 Total Submissions: 251280 Difficulty: Medium
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.

*/

class Solution {
public:

    //方法一，用O(N)的方法来实现
    int findMin_test(vector<int>& nums) {
        if(nums.size()<=1)return nums[0];
        int n = nums.size();
        for(int i=0;i<n-1;++i)
        {
            if(nums[i+1]<nums[i])return nums[i+1];
        }
        
        //没有
        return nums[0];
    }
    
    int binarySearch(int start,int end,vector<int>&nums)
    {
        int ret = 65535;
        while(start<=end)   //边界条件,WTF
        {
            int mid = start+(end-start)/2;
            if(nums[start]<=nums[end])  //这是经过几轮的查找后，找到了在一个有序数组中
            {
                return nums[start]<ret?nums[start]:ret;
            }
            if(nums[mid]>=nums[start])  //中间点在左边部分，如果在右边的话，中间点不可能大于左边的值
            {
                start = mid+1;
            }
            else                        //中间点在右边部分,往左边搜
            {
                //nums[mid] < nums[start]
                ret = nums[mid];  //记录下这个小的值
                end = mid-1;    //因为这里mid+1了，所以有可能会错过最小值，所以需要事先保存最小值
            }
        }
       
      
        return nums[start]<ret?nums[start]:ret;
    }
    
    //方法二，二分查找 log(n)
     int findMin(vector<int>& nums) 
     {
         return binarySearch(0,nums.size()-1,nums);
     }
};