/*
241. Different Ways to Add Parentheses My Submissions QuestionEditorial Solution
Total Accepted: 23713 Total Submissions: 65640 Difficulty: Medium
Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.


Example 1
Input: "2-1-1".

((2-1)-1) = 0
(2-(1-1)) = 2
Output: [0, 2]
*/
class Solution {
public:
   //divid and conquer
    vector<int> diffWaysToCompute(string input) {
        int n=input.size();
        vector<int>ret;
        
        if(input.find_first_of("+-*")==string::npos)
        {
            ret.push_back(stoi(input));
            return ret;
        }
        
        for(int i = 0;i<n;++i)
        {
            if(input[i]=='+'||input[i]=='-'||input[i]=='*')
            {
                string left = input.substr(0,i);
                string right = input.substr(i+1);
                auto left_num = diffWaysToCompute(left);
                auto right_num = diffWaysToCompute(right);
                
                for(auto&l:left_num)
                {
                    for(auto&r:right_num)
                    {
                        if(input[i]=='+')
                        {
                            ret.push_back(l+r);
                        }
                        else if(input[i]=='-')
                        {
                            ret.push_back(l-r);
                        }
                        else if(input[i]=='*')
                        {
                            ret.push_back(l*r);
                        }
                    }
                }
            }
        }
        
        return ret;
        
    }
};