/*
171. Excel Sheet Column Number My Submissions QuestionEditorial Solution
Total Accepted: 81829 Total Submissions: 193769 Difficulty: Easy
Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
	*/
	
//其实就是26进制的计算
class Solution {
public:
    int titleToNumber(string s) {
        int res=0;
        int n = s.size();
        if(n==0)return 0;
        for(int i=n-1;i>=0;--i)
        {
            res+=(s[i]-'A'+1)*pow(26,n-i-1);
        }
        
        return res;
    }
};
	