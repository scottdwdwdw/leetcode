/*
*Given an array of integers, find out whether there are two distinct indices 
i and j in the array such that the difference between nums[i] and nums[j] is at
 most t and the difference between i and j is at most k.
*
*/

//˼·��
//�����ƽ⣬����k��С�Ĵ��ڣ�ѭ���Ƚϣ�˫��ѭ��


//2,ͬ���Ƿ���k����С�Ĵ��ڣ�����k��ֵ������������������У���ô�����Ƚϵĸ��ӶȾͽ�Ϊlogk,��ô�ܹ��ĸ��ӶȾͱ�Ϊ,n*log(n);

//����
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(k<=0)return false;   //k distance
        std::multiset<int>window;
        for(int i=0;i<nums.size();++i)  
        {
            if(i>k)window.erase(nums[i-k-1]);  //�Ƴ����ڣ��Ѿ��ȽϹ�����ǰk���в�����<=t����������ô�ƶ����ڣ��Ͳ�����С��k������������ɾ��ǰ���Ԫ��
            auto pos=window.lower_bound(nums[i]-t);//nums[i]-t<=nums[j]---> nums[i]-nums[j]<=t    
            if(pos!=window.end()&&*pos-nums[i]<=t)return true;//nums[j]-nums[i]<=t;//�ٴ�ȷ�ϴ�С��ϵ   �������ε�ȷ����|nums[i]-nums[j]|<=t
            
            window.insert(nums[i]);
            
        }
        
        return false;
    }