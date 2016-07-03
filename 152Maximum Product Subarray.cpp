/*
152. Maximum Product Subarray My Submissions QuestionEditorial Solution
Total Accepted: 59914 Total Submissions: 267992 Difficulty: Medium
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.

Subscribe to see which companies asked this question

*/

class Solution {
public:
    //使用动态规划，
    //状态转移方程：
    // max_product[i] = max (max(max_product[i-1]*nums[i],min_product[i-1]*nums[i]),nums[i]);
    // min_product[i] = min(min(max_product[i-1]*nums[i],min_product[i-1]*nums[i]),nums[i]);
	//注意这里状态方程，为什么是和nums[i]比较大小，因为题目要求是计算相邻的数的乘机
    // max_product[i]  表示以i为结束下标的数组
    int maxProduct(vector<int>& nums) {
        int m = nums.size();
        vector<int>max_product(m,0);  //这个实际相当于一个备忘录
        vector<int>min_product(m,0);
        max_product[0] = nums[0];
        min_product[0] = nums[0];
        int ans = nums[0];
        for(int i=1;i<m;++i)
        {
            int max_temp=0;
            int min_temp=0;
            if(nums[i]>0) //max_product[i] = max(max_product[i-1]*nums[i],nums[i])
            {
                max_temp = max(max_product[i-1]*nums[i],nums[i]);
                min_temp = min(min_product[i-1]*nums[i],nums[i]);
            }
            else if(nums[i]<0)
            {
                max_temp = max(min_product[i-1]*nums[i],nums[i]);
                min_temp = min(max_product[i-1]*nums[i],nums[i]);
            }
            
            max_product[i] = max_temp;
            min_product[i] = min_temp;
            
            ans = max(max_product[i],ans);
        }
        
        return ans;
    }
};