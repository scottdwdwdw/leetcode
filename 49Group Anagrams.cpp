/*
49. Group Anagrams My Submissions QuestionEditorial Solution
Total Accepted: 77238 Total Submissions: 276505 Difficulty: Medium
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:
For the return value, each inner list's elements must follow the lexicographic order.
All inputs will be in lower-case.

*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        map<string ,vector<string>>res_temp;
        vector<vector<string>>ret;
          if(n==0)return ret;
        for(int i=0;i<n;++i)
        {
           string temp = strs[i];
           sort(temp.begin(),temp.end());
           res_temp[temp].push_back(strs[i]);
        }
        
        for(auto&e:res_temp)
        {
            sort(e.second.begin(),e.second.end());
            ret.push_back(e.second);
        }
        
        return ret;
    }
};