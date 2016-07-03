/*
202. Happy Number My Submissions QuestionEditorial Solution
Total Accepted: 70763 Total Submissions: 192014 Difficulty: Easy
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/
/*
	这种方法会超时
*/
class Solution {
public:
    bool isHappy(int n) {
        set<int>res_set;
        res_set.insert(-1);
        int mult=0;
        string num = to_string(n);
        while(mult!=1)
        {
            for(int i=0;i<num.size();++i)
            {
                int temp = num[i]-'0';
                mult += temp*temp;
            }
            if(mult==1)return true;
            if(res_set.count(mult)==0)res_set.insert(mult);
            else
            {
                return false;
            }
			
			num = to_string(mult);
        }
        
        return true;
    }
};


class Solution {
public:
    bool isHappy(int n) {
        map<int,int>res_set;
        int mult=0;
        int d=0;
        while(mult!=1)
        {
            mult = 0;
            while(n!=0)  //循环计算乘积
            {
                d = n%10;
                mult += d*d;
                n = n/10;
            }
            if(mult==1)return true;
            if(res_set[mult]==0)res_set[mult]=1;
            else
            {
                return false;
            }
            n = mult;
           
        }
        
        return true;
    }
};