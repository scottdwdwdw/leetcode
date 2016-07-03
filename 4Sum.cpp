/*
18. 4Sum   My Submissions QuestionEditorial Solution
Total Accepted: 72620 Total Submissions: 304367 Difficulty: Medium
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
	
*/


//4sum转换为3sum，再转换为2sum

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
       
       
        vector<vector<int>>res;
        if(nums.size()<=3)return res;
        
        sort(nums.begin(),nums.end());   //先排序
        
        /*****这样做的复杂度是o(n^3)  可行？********/
        for(int i = 0; i<nums.size()-3;)
        {
            int sub_target = target-nums[i];  //得到3sum的和
            //求3sum 
            for(int j = i+1;j<nums.size()-2;)
            {
                int sub_sub_target = sub_target-nums[j];
                //求2sum
                int left = j+1;
                int right = nums.size()-1;
                
                while(left<right)
                {
                   int sum = nums[left]+nums[right];
                   int old_left=nums[left];
                   int old_right = nums[right];
                   if(sum<sub_sub_target)
                   {
                       while(left<right&&nums[left]==old_left)++left;
                   }
                   else if(sum>sub_sub_target)
                   {
                      while(left<right&&nums[right]==old_right)--right;
                   }
                   else  //result
                   {
                       vector<int>temp(4,0);
                       temp[0] = nums[i];
                       temp[1] = nums[j];
                       temp[2] = nums[left];
                       temp[3] = nums[right];
                       res.push_back(temp);
                       
                       while(left<right&&old_left==nums[left])++left;
                       while(left<right&&old_right==nums[right])--right;
                   }
                }
                int old_val = nums[j];
                while(j<nums.size()-2&&nums[j]==old_val)++j;
            }   
            int old_ = nums[i];
            while(i<nums.size()-3&&nums[i]==old_)++i;
        }
        return res;
    }
};