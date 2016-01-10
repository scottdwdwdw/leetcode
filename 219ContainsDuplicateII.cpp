/*
Given an array of integers and an integer k, 
find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] 
and the difference between i and j is at most k.
*/
//ÎÒµÄ´úÂë
bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        std::map<int,std::vector<int>>res;
        for(int i=0;i<n;++i)
        {
            
            res[nums[i]].push_back(i);
        }
        for(auto it=res.begin();it!=res.end();++it)
        {
            int max_dis=-1;
            if((*it).second.size()<=1)continue;
            for(auto it2=(*it).second.begin()+1;it2!=(*it).second.end();++it2)
            {
                max_dis=*(it2)-*(it2-1);
                if(max_dis<=k)return true;
            }
        }
        return false;
    }

//