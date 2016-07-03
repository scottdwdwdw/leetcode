/*
168. Excel Sheet Column Title My Submissions QuestionEditorial Solution
Total Accepted: 62662 Total Submissions: 283867 Difficulty: Easy
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
*/

class Solution {
public:
   //26进制的反转
    string convertToTitle(int n) {
        vector<int>res;
        string ret;
        while(n)
        {
            int temp = n%26;
            res.push_back(temp);
            n = n/26;
        }
        //if(res.size()>1)res[0]+=1;
        int carry=0;
        int m = res.size();
       for(int i=0;i<m;++i)
        {
            if(res[i]==0)
            {
               res[i]=26;
               carry=1;
            }
            else
            {
                res[i]-=carry;
                if(res[i]==0&&i<m-1)res[i]=26;
                else
                {
                    carry=0;
                }
            }
            
        }
      
       
        for(int i=res.size()-1;i>=0;--i)
        {
           if(res[i]>0&&res[i]<=26)ret+='A'+(res[i]-1);
        }
        
        return ret;
    }
};