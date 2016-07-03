
/*
263. Ugly Number My Submissions QuestionEditorial Solution
Total Accepted: 58850 Total Submissions: 158793 Difficulty: Easy
Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.

Note that 1 is typically treated as an ugly number.
*/

class Solution {
public:
   //�������ο����˵ģ�
   // 1 return true, 0 return false, 6����2��ʣ3����������3������1, ����14,14����2��Ϊ7,7��������2,3,5������һ��
    bool isUgly(int num) {
        if(num<=0)return false;
        if(num == 1)return true;
        
        while(num>=2&&num%2==0)num=num/2;
        while(num>=3&&num%3==0)num=num/3;
        while(num>=5&&num%5==0)num=num/5;
        
        
        return num==1;
    }
};