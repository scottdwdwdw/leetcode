/*
258. Add Digits My Submissions QuestionEditorial Solution
Total Accepted: 98470 Total Submissions: 201981 Difficulty: Easy
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example:

Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

Follow up:
Could you do it without any loop/recursion in O(1) runtime?

Hint:

A naive implementation of the above process is trivial. Could you come up with other methods?
What are all the possible results?
How do they occur, periodically or randomly?
You may find this Wikipedia article useful.
*/

class Solution {
public:
   //方法1；用递归
    int addDigits(int num) {
        if(num/10==0)return num;
        int sum=0;
        while(num)
        {
            sum+=num%10;
            num = num/10;
        }
        return addDigits(sum);
    }
};

    //方法2：很巧妙
    //左边是数字，右边是所有数位的和
/*
0 0
1 1
2 2
3 3
4 4
5 5
6 6
7 7
8 8
9 9
10 1
11 2
12 3
13 4
14 5
15 6
16 7
17 8
18 9
19 1
20 2
21 3
22 4
23 5
24 6
25 7
26 8
27 9
28 1
29 2*/

 int addDigits(int num) {
        if(num==0)return 0;
       
        return (num-1)%9+1;
    }
};