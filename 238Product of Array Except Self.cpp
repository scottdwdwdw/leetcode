/*238. Product of Array Except Self

Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].
*/

//[a0,a1,a2,a3] ===> [1,a0,a0*a1,a0*a1*a2]
//					 [a3*a2*a1,a3*a2,a3,1]

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> arr_temp;
        int res_temp = 1;
        arr_temp.push_back(res_temp);
        for(int i=0;i<nums.size()-1;++i)
        {
            res_temp *= nums[i];
            arr_temp.push_back(res_temp);
        }
        res_temp = 1;
        vector<int> arr_temp2;
        arr_temp2.push_back(res_temp);
        for(int i=nums.size()-1;i>=1;--i)
        {
            res_temp *= nums[i];
            arr_temp2.push_back(res_temp);
        }
        
        vector<int>res;
        for(int i=0;i<nums.size();++i)
        {
            res.push_back(arr_temp[i]*arr_temp2[nums.size()-1-i]);
        }
        
        
        return res;
    }
};

//¸´ÔÓ¶È£¬O(n)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>res(nums.size());
        int temp=1;
        res[0]=temp;
        for(int i=0;i<nums.size()-1;++i)
        {
            temp =temp*nums[i];
            res[i+1] = temp;
        }
        
    
        temp = 1;
        res[nums.size()-1]=res[nums.size()-1]*temp;
        int j =nums.size()-2;
        for(int i=nums.size()-1;i>=1;--i)
        {
            temp*=nums[i];
            res[j--] *= temp;
        }
        
    
        
        
        return res;
    }
};