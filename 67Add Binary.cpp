/*
67. Add Binary My Submissions QuestionEditorial Solution
Total Accepted: 87280 Total Submissions: 313443 Difficulty: Easy
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/

class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size();
        int n = b.size();
        string res;
        char carry='0';
        int i=m-1;
        int j=n-1;
        for(;i>=0&&j>=0;--i,--j)
        {
            char temp = '0'+(a[i]-'0'+b[j]-'0')+(carry-'0');
            if(temp=='3')
            {
                temp='1';
                carry = '1';
            }
            else if(temp=='2')
            {
                temp='0';
                carry = '1';
            }
            else if(temp=='1'||temp=='0')
            {
                carry='0';
            }
            res.insert(0,1,temp);
        }
        while(i>=0)
        {
            char temp = '0'+(a[i]-'0'+carry-'0');
            if(temp=='2')
            {
                temp='0';
                carry='1';
            }
            else if(temp=='1'||temp=='0')
            {
                carry='0';
            }
            res.insert(0,1,temp);
            --i;
        }
        while(j>=0)
        {
            char temp = '0'+(b[j]-'0'+carry-'0');
            if(temp=='2')
            {
                temp='0';
                carry='1';
            }
            else if(temp=='1'||temp=='0')
            {
                carry='0';
            }
            res.insert(0,1,temp);
            --j;
        }
        if(carry=='1')res.insert(0,1,carry);
        
       // string ret(res.rbegin(),res.rend());
        return res;
    }
};