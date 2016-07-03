/*
17. Letter Combinations of a Phone Number My Submissions QuestionEditorial Solution
Total Accepted: 83780 Total Submissions: 286061 Difficulty: Medium
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

*/

class Solution {
public:

    void helper(int index,int num,string&digits,vector<string>&res,string&res_temp,map<char,char>&num2char)
    {
        int n=3;
        if(num==7||num==9)n=4;
        if(res_temp.size()==digits.size())
        {
            res.push_back(res_temp);
            return;
        }
        for(int i=0;i<n;++i)
        {
            res_temp.push_back(num2char[num]+i);
            int next = digits[++index]-'0';
            helper(index,next,digits,res,res_temp,num2char);
            --index;
            res_temp.pop_back();
        }
    }
   //应该暴力求解
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        vector<string>ret;
        if(n==0)return ret;
        map<char,char>num2char;
        for(int i=2;i<=9;++i)
        {
            if(i==8)num2char[i]='t';
            else if(i==9)num2char[i]='w';
            else
            {
               num2char[i]='a'+3*(i-2);
            }
        }
        size_t pos = digits.find_first_of("10*#");
        if(pos!=string::npos)return ret;
        int num = digits[0]-'0';
        string res_temp;
        helper(0,num,digits,ret,res_temp,num2char);
        
        return ret;
        
    }
};