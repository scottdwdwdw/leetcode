/*Given an array of size n, find the majority element. The majority element is the element that appears more than ? n/2 ? times.
You may assume that the array is non-empty and the majority element always exist in the array.
*/
//注意题目中说的 
//You may assume that the array is non-empty and the majority element always exist in the array.
 int majorityElement(vector<int>& nums) {
          sort(nums.begin(), nums.end());
           return nums[nums.size()/2];
    }