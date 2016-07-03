
/*
22. Generate Parentheses My Submissions QuestionEditorial Solution
Total Accepted: 92000 Total Submissions: 243881 Difficulty: Medium
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

*/

class Solution {
public:
    //参考disscus 最高票答案，使用递归
    //n记录左括号的个数，m记录右括号的个数
    //当使用了一个左括号，那么n-1,相应的m应该增加。当使用了一个右括号，左括号个数不变
    vector<string> generateParenthesis(int n) {
        vector<string>ret;
        string s;
        helper(ret,s,n,0);
        return ret;
    }
    
    void helper(vector<string>&res,string s,int n,int m)
    {
        if(n==0&&m==0)
        {
            res.push_back(s);
            return;
        }
        if(m>0){helper(res,s+")",n,m-1);}   //添加右括号
        if(n>0){helper(res,s+"(",n-1,m+1);} //添加左括号
    }
};