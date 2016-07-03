/*
326. Power of Three My Submissions QuestionEditorial Solution
Total Accepted: 44884 Total Submissions: 120637 Difficulty: Easy
Given an integer, write a function to determine if it is a power of three.

Follow up:
Could you do it without using any loop / recursion?

*/
class Solution {
public:
   //方法1：
   //递归，其实也就是循环了
   //方法2：
   //3^x = n  =>  log(3^x) = log(n) =>  x*log(3) = log(n)  =>  x = log(n)/log(3);
   /* bool isPowerOfThree(int n) {
        if(n==1)return true;
        else if(n==0)return false;
        if(n%3==0)
        {
            return isPowerOfThree(n/3);
        }
        else
        {
            return false;
        }
    }*/
    //方法2：
      bool isPowerOfThree(int n) {
         double logans = log10(n)/log10(3);
         return (logans-(int)logans)==0?true:false;
    }
};