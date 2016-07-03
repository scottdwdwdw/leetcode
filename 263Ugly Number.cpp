
/*
263. Ugly Number My Submissions QuestionEditorial Solution
Total Accepted: 58850 Total Submissions: 158793 Difficulty: Easy
Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.

Note that 1 is typically treated as an ugly number.
*/

class Solution {
public:
   //方法，参考别人的，
   // 1 return true, 0 return false, 6除以2后，剩3，可以整除3，等于1, 又如14,14除以2后为7,7并能整除2,3,5的任意一个
    bool isUgly(int num) {
        if(num<=0)return false;
        if(num == 1)return true;
        
        while(num>=2&&num%2==0)num=num/2;
        while(num>=3&&num%3==0)num=num/3;
        while(num>=5&&num%5==0)num=num/5;
        
        
        return num==1;
    }
};