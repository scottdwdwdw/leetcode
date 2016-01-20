/*
*Given an array of integers, find out whether there are two distinct indices 
i and j in the array such that the difference between nums[i] and nums[j] is at
 most t and the difference between i and j is at most k.
*
*/

//思路：
//暴力破解，分配k大小的窗口，循环比较，双层循环


//2,同样是分配k个大小的窗口，把这k个值存放在搜索二叉树当中，那么搜索比较的复杂度就降为logk,那么总共的复杂度就变为,n*log(n);

//代码
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(k<=0)return false;   //k distance
        std::multiset<int>window;
        for(int i=0;i<nums.size();++i)  
        {
            if(i>k)window.erase(nums[i-k-1]);  //移除窗口，已经比较过，在前k个中不符合<=t的条件，那么移动窗口，就不满足小于k的条件，所以删除前面的元素
            auto pos=window.lower_bound(nums[i]-t);//nums[i]-t<=nums[j]---> nums[i]-nums[j]<=t    
            if(pos!=window.end()&&*pos-nums[i]<=t)return true;//nums[j]-nums[i]<=t;//再次确认大小关系   所以两次的确定是|nums[i]-nums[j]|<=t
            
            window.insert(nums[i]);
            
        }
        
        return false;
    }