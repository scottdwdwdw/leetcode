
/*
209. Minimum Size Subarray Sum
Total Accepted: 38553 Total Submissions: 142853 Difficulty: Medium
Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.
*/
class Solution {
public:
    //伸缩窗口法
    int minSubArrayLen(int s, vector<int>& nums) {
        int start = 0;
        int end = 0;
        int sum = 0;
        int min_length = 65535;
        while(end<nums.size())
        {
           while(sum<s&&end<nums.size())
           {
               sum+=nums[end++];    //end会指向当前条件的下一个点，所以在后边的计算min_length的时候，就不+1了。
           }
           while(sum>=s)
           {
               min_length = min_length<=(end-start)?min_length:end-start;
               if(min_length==1)return min_length;
               sum-=nums[start];
               ++start;
           }
        }
        
        return min_length==65535?0:min_length;
    }
};


//二分查找，能把复杂度降为 n(log(n)
class Solution {
public:
    //二分查找
    int binary_search(int start,int end,int key,int*nums)
    {
        int mid;
        while(start<=end)
        {
            mid = (end+start)/2;
            if(nums[mid]>=key)
            {
                end = mid-1;
            }
            else
            {
                start = mid+1;
            }
        }
        
        return start;
    }
    int minSubArrayLen(int s, vector<int>& nums) {   //sum[3]-sum[0] = num[1]+num[2]+num[3];   sum[4]-sum[1]=num[2]+num[3]+num[4]
       int *sums_arr = new int[nums.size()+1]();
       int min_length=65535;
       for(int i=1; i<nums.size();++i)
       {
           sums_arr[i] = sums_arr[i-1]+nums[i-1];
       }
       
       for(int i=0;i<(nums.size()+1);++i)
       {
           int end = binary_search(i+1,nums.size(),sums_arr[i]+s,sums_arr); //第一个元素没有用，
           if(end == nums.size()+1)break;
           if(end-i<min_length)min_length=end-i;
       }
        
        return min_length==65535?0:min_length;
    }
};
