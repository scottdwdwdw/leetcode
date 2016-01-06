/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/

 void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<nums.size();)
        {
            if(nums[i]==0)nums.erase(nums.begin()+i);
            else ++i;
        }
        int count=n-nums.size();
        nums.insert(nums.end(),count,0);
    }
	
	
	
//较好方法
     int j = 0;
        // move all the nonzero elements advance
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[j++] = nums[i];
            }
        }
        for (;j < nums.size(); j++) {
            nums[j] = 0;
        }