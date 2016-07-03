/*
15. 3Sum   My Submissions QuestionEditorial Solution
Total Accepted: 117100 Total Submissions: 620637 Difficulty: Medium
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
*/
class Solution {
public:
    //a+b+c=0 ==> a+b=-c  首先计算所有的a+b，存入multi_map,然后再查找是否存在a+b=-c;
    /*vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ret;
        multimap<int,vector<int>>mm;
        if(nums.size()<=2)return ret;
        //1.存储
        for(int i=0;i<nums.size()-1;++i)
        {
            for(int j=i+1;j<nums.size();++j)
            {
                vector<int>temp(2,0);
                temp[0] = nums[i];
                temp[1] = nums[j];
                mm.insert({nums[i]+nums[j],temp});
            }
        }
        
        //查找
         vector<int>res_temp(3,0);
        for(int i=0;i<nums.size();++i)
        {
            auto entries = mm.count(-nums[i]);
            if(entries>0)
            { 
                auto iter = mm.find(-nums[i]);
                while(entries)
                {
                    res_temp[0]=(*iter).second[0];
                    res_temp[1]=(*iter).second[1];
                    res_temp[2]=nums[i];
                    sort(res_temp.begin(),res_temp.end());
                    ret.push_back(res_temp);
                    --entries;
                    ++iter;
                }
            }
        }
        
        
        //最后还需要去重，而且也会出现相等元素的情况
        //不用这种方法
        return ret;
    }
    */
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>>ret;
        if(nums.size()<3)return ret;
        sort(nums.begin(),nums.end());
        vector<int>res_temp(3,0);
        
        for(int i=0;i<nums.size()-1;++i)
        {
            int key = -nums[i];
            int start = i+1;
            int end = nums.size()-1;
            while(start<end)
            {
                if((nums[start]+nums[end])==key)
                {
                    res_temp[0] = -key;
                    res_temp[1] = nums[start];
                    res_temp[2] = nums[end];
                    ret.push_back(res_temp);
                    while(start<end&&nums[start]==res_temp[1])++start;  //避开重复点
                    while(start<end&&nums[end]==res_temp[2])--end;
                }
                else if((nums[start]+nums[end])<key)
                {
                    ++start;
                }
                else
                {
                    --end;
                }
            }
            
            while(i+1<nums.size()&&nums[i+1]==nums[i])++i;  //跳过相同的点，因为如果是相同的点，他们的解也会是一样的，所以跳过
        }
        
        return ret;
    }
};