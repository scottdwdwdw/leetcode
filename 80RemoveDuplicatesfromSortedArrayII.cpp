/*
*
*  Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
*/

//±©Á¦ÆÆ½â
    int removeDuplicates(vector<int>& nums) {
        auto n=nums.size();
        size_t i=0;
        while(i<n)
        {
            if(nums[i]==nums[i+1])
            {
                size_t j=i+2;
                while(j<n&&nums[i]==nums[j])
                {
                    nums.erase(nums.begin()+j);
                    --n;   
                }
            }
            ++i;
        }
        
        return n;
    }
	
//ÈüÅÜ¡£¡£¡£tow-pointer
int removeDuplicates(vector<int>& nums) {
    int n = nums.size(), count = 0;
    for (int i = 2; i < n; i++)
        if (nums[i] == nums[i - 2 - count]) count++;
        else nums[i - count] = nums[i];
    return n - count;
}