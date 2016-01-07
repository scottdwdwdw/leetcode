/*Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
*/
//ÎÒµÄ´úÂë
 bool containsDuplicate(vector<int>& nums) {
        auto it2=nums.end();
        std::sort(nums.begin(),nums.end());
        auto it =std::unique(nums.begin(),nums.end());
        return !(it==it2);
 }

//