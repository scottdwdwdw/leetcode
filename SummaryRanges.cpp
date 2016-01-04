/*
*
*  1.Given a sorted integer array without duplicates, return the summary of its ranges.
*   For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
*/

//我的代码：
 vector<string> summaryRanges(vector<int>& nums) {
        vector<string>result;
        std::string sbegin;
        std::string send;
        if(nums.size()==1)
        {
            result.push_back(to_string(nums[0]));
            return result;
        }
        std::vector<int>::iterator it_begin;
        auto it=nums.begin();
        auto next=std::next(it);
        bool _begin=true;  //flag
        for(;it!=nums.end();++it,++next)
        {
            if(_begin)
            {
                it_begin=it;
                _begin=false;
            }
            if(next==nums.end())
            {
                if(it!=it_begin)
                {
                    result.push_back(to_string(*it_begin)+"->"+to_string(*it));
                }
                else
                {
                    result.push_back(to_string(*it));
                }
            }
            else if((*it+1)!= *next)
            {
                _begin=true;
                if(it!=it_begin)
                {
                   result.push_back(to_string(*it_begin)+"->"+to_string(*it));
                }
                else
                {
                     result.push_back(to_string(*it));
                }
            }
        }
        
        return result;
        
    }
	
//由于vector的底层实现是一块连续的内存，且可以随机存取，所以不使用迭代器来提高效率。
//推荐代码：
vector<string> summaryRanges(vector<int>& nums) {
    int n = nums.size();
    vector<string> res;
    int i = 0;
    while(i<n){
        res.push_back(to_string(nums[i]));
        int j = i+1;
        while(j<n && nums[j]==nums[j-1]+1)++j;
        if(j>i+1){//more than one consecutive number
            res.back()+="->"+to_string(nums[j-1]);
        }//else just single number
        i=j;
    }
    return res;
}