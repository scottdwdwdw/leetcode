/*
303. Range Sum Query - Immutable My Submissions QuestionEditorial Solution
Total Accepted: 34355 Total Submissions: 136932 Difficulty: Easy
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3

*/

class NumArray {
public:
   // 这种方法错了，没有必要开辟这么大的空间
   /*
    NumArray(vector<int> &nums) {
        nums = nums;
        n = nums.size();
        
        for(int i=0;i<n;++i)
        {
            vector<int>temp;
            temp.push_back(nums[i]);
            dp.push_back(temp);
        }
        
        //dp  递推公式: dp[i][j] = dp[i][j-1]+nums[j];
        for(int i = 0 ; i<n;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                dp[i].push_back(dp[i][j-i-1]+nums[j]);
            }
        }
        
    }

    int sumRange(int i, int j) {
        return dp[i][j-i];
    }
private:
    //int **dp;  //这种方法内存超了
    vector<vector<int>>dp; //超时了
    vector<int>nums;
    int n;
    */
    
    NumArray(vector<int> &nums) {
       int n = nums.size();
       if(n != 0)
       {
            sums.push_back(nums[0]);
            for(int i=1;i<n;++i)
            {
               sums.push_back(nums[i]+sums[i-1]);  //求0-i的和
            }
            len = n;
       }
    }

    int sumRange(int i, int j) {
        if(len == 0)return 0;
        int ans;
        if(i==0)ans = sums[j];
        else if(j<len&&i<=j&&i>0)
        {
            ans = sums[j]-sums[i-1];
        }
        
        return ans;
    }
private:
    vector<int>sums;
    int len;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);