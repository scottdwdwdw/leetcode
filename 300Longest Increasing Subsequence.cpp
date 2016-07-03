300. Longest Increasing Subsequence
/*
300. Longest Increasing Subsequence My Submissions QuestionEditorial Solution
Total Accepted: 33501 Total Submissions: 95663 Difficulty: Medium
Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?
*/
class Solution {
public:
    //肯定是动态规划解题
    //递推公式：???
    //o(n^2)复杂度
    //但如果在中间的搜索使用二分查找，就能把复杂度降为o(nlog(n))
    //dp[i] = max(dp[j]+1,dp[i]), 0<=j<i;
    //两层遍历,
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n==0)return 0;
        vector<int>dp(n,1);
        for(int i = 0;i<n;++i)
        {
            for(int j=0;j<i;++j)
            {
                if(nums[j]<nums[i]&&(dp[j]+1>dp[i]))
                {
                    dp[i] = dp[j]+1;
                }
            }
        }
        int max = dp[0];
        
        for(int i=0;i<n;++i)
        {
            if(dp[i]>max)max=dp[i];
        }
        
        return max;
    }
};

    //O(nlog(n))是维护一个单调递增序列
    //遍历数列，查找每个数的位置
    //
    
     int binarySearch(vector<int>&nums,int left,int right,int target)
     {
         int mid=0;
         while(left!=right)
         {
            mid = left+(right-left)/2;
            if(target>nums[mid])
            {
                left = mid+1;
            }
            else 
            {
                right = mid;
            }
         }
         
         return left;
     }
     
     int lengthOfLIS(vector<int>& nums) {
        vector<int>lis;
        for(auto&e:nums)
        {
            int insert_pos = binarySearch(lis,0,lis.size(),e);
            if(insert_pos>=lis.size())lis.push_back(e);
            else
            {
                lis[insert_pos] = e;
            }
        }
        
        return lis.size();
    }
};