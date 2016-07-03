
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
    //�ο�disscus ���Ʊ�𰸣�ʹ�õݹ�
    //n��¼�����ŵĸ�����m��¼�����ŵĸ���
    //��ʹ����һ�������ţ���ôn-1,��Ӧ��mӦ�����ӡ���ʹ����һ�������ţ������Ÿ�������
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
        if(m>0){helper(res,s+")",n,m-1);}   //���������
        if(n>0){helper(res,s+"(",n-1,m+1);} //���������
    }
};