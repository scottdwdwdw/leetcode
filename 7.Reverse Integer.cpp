/*
7. Reverse Integer My Submissions QuestionEditorial Solution
Total Accepted: 143620 Total Submissions: 606161 Difficulty: Easy
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.

Subscribe to see which companies asked this question

Show Tags
Show Similar Problems
*/


class Solution {
public:
    //思路，把该数字拆分，存入一个vector中，用一个标志位存储符号位。
    //然后再组合
    //主要是考虑溢出的问题，如果上溢出，得到的结果是负数，下溢出，得到的结果是整数
    int reverse(int x) {
        int bit_count = 0;
        int copy_x = abs(x);
        bool neg = false;
        int new_x=0;
        vector<int>bit_record;
        if(x<0)neg=true;
        while(copy_x!=0)
        {
            bit_record.push_back(copy_x%10);   
            copy_x/=10;
            bit_count++; 
        }
        for(int i=0;i<bit_record.size();++i)
        {
            new_x+=bit_record[i]*pow(10,bit_count-1-i);
            if(new_x<0)//溢出
            {
                return 0;
            }
        }
        if(neg)
        {
            new_x = -new_x;
            if(new_x>0)return 0;
        }
        
        return new_x;
    }
};