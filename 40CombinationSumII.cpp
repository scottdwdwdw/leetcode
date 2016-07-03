/*
40. Combination Sum II My Submissions QuestionEditorial Solution
Total Accepted: 68891 Total Submissions: 248718 Difficulty: Medium
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, �� , ak) must be in non-descending order. (ie, a1 �� a2 �� �� �� ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 
*/

class Solution {
public:
    //ʹ�ñ�������,ÿ��������Ĵ�ֻ����ʹ��һ��
    void brute_search(int start,vector<int>&candidates,int target,vector<vector<int>>&ret,vector<int>&res,int sum)
    {
        if(sum==target)
        {
            vector<int>res_copy = res;
            sort(res_copy.begin(),res_copy.end());
            ret.push_back(res_copy);    //������ֵ
        }
        else if(sum<target) //���sum<target���ݹ���ã����sum>target
        {
            for(int i = start;i<candidates.size();)
            {
                sum+=candidates[i];
                res.push_back(candidates[i]); //��ջ
                brute_search(i+1,candidates,target,ret,res,sum);
                sum-=candidates[i];
                int old_value = res.back();
                res.pop_back();   //����
                while(i<candidates.size()&&candidates[i]==old_value)++i;  //��ͬ����Ͳ�����,ֻ��һ��
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ret;
        vector<int>res_temp;
        sort(candidates.begin(),candidates.end());
        brute_search(0,candidates,target,ret,res_temp,0);
        return ret;
    }
};