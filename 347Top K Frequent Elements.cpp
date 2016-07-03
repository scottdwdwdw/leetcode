/*
347. Top K Frequent Elements My Submissions QuestionEditorial Solution
Total Accepted: 11994 Total Submissions: 28421 Difficulty: Medium
Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].
*/

bool value_compare(std::pair<int,int>a,std::pair<int,int>b)
    {
        return a.second>b.second;
    }

class Solution {
public:
    
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>arr;
        vector<int>res;
        int n=nums.size();
        vector<std::pair<int,int>>arr_temp;
        for(int i=0;i<n;++i)
        {
           if(arr[nums[i]]==0)
           {
               arr[nums[i]]+=1;
           }
           else
           {
                arr[nums[i]]+=1;
           }
        }
        for(auto&e:arr)
        {
            auto temp = std::make_pair(e.first,e.second);
            arr_temp.push_back(temp);
        }
        sort(arr_temp.begin(),arr_temp.end(),value_compare);
        
        for(int i=0;i<k;++i)
        {
            res.push_back(arr_temp[i].first);
        }
        
        return res;
    }
};

//这是map和优先队列做的
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(int num : nums){
            map[num]++;
        }

        vector<int> res;
        // pair<first, second>: first is frequency,  second is number
        priority_queue<pair<int,int>> pq; 
        for(auto it = map.begin(); it != map.end(); it++){
            pq.push(make_pair(it->second, it->first));
            if(pq.size() > (int)map.size() - k){
                res.push_back(pq.top().second);
                pq.pop();
            }
        }
        return res;
    }
};