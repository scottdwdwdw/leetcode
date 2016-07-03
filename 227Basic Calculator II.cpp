227. Basic Calculator II My Submissions QuestionEditorial Solution
Total Accepted: 24434 Total Submissions: 95061 Difficulty: Medium
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

You may assume that the given expression is always valid.

Some examples:
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5

class Solution {
public:
    //思路，两个队列，一个存储操作数，一个存储操作符，
    //如果遇到* /则先计算后，再把计算的结果存入操作数队列中
    int calculate(string s) {
        int n = s.size();   
        vector<int>nums;
        vector<char>op;
        for(int i=0;i<n;)
        {
            while(s[i]==' ')++i;
            int j=i;
            while(s[j]>='0'&&s[j]<='9'&&j<n)++j;
            string num_str = s.substr(i,j-i);
    
            int num_temp = stoi(num_str);
          // int num_temp = n;
            nums.push_back(num_temp);
            
            i = j;
            while(i<n&&s[i]==' ')++i;
            if(i>=n)break;
            if(s[i]=='*'||s[i]=='/'||s[i]=='+'||s[i]=='-')
            {
                op.push_back(s[i]);
            }
            ++i;
        }
        
        for(int i=0;i<op.size();++i)
        {
            int num = 0;
            if(op[i]=='*')
            {
              num = nums[i]*nums[i+1];
              nums[i]=num;
              nums.erase(nums.begin()+i+1);
              op.erase(op.begin()+i);
              --i;
            }
            else if(op[i]=='/')
            {
                num = nums[i]/nums[i+1];
                nums[i]=num;
                nums.erase(nums.begin()+i+1);
                op.erase(op.begin()+i);
                --i;
            }
        }
        int res = nums[0];
        for(int i=0;i<op.size();++i)
        {
            if(op[i]=='+')
            {
                res +=nums[i+1];
            }
            else if(op[i]=='-')
            {
                res-=nums[i+1];
            }
        }
        
        return res;
    }   
};