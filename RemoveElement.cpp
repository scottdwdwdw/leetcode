/*
Given an array and a value, remove all instances of that value in place and return the new length.
The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/

//我的代码： 使用STL函数
  int removeElement(vector<int>& nums, int val) {
        for(auto i=nums.begin();i!=nums.end();)
        {
            if(*i==val)nums.erase(i);
            else ++i;
        }
        return nums.size();
    }
	
//
int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        vector<int>res;
        for(int i=0;i<n;++i)
        {
            if(nums[i]!=val) res.push_back(nums[i]);
        }
        nums=std::move(res);
        return nums.size();
    }