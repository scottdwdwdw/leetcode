/*
231. Power of Two My Submissions QuestionEditorial Solution
Total Accepted: 77168 Total Submissions: 207714 Difficulty: Easy
Given an integer, write a function to determine if it is a power of two.
*/

class Solution {
public:
    //和 power of 3 思路一样，2^x = n  => log2^x = logn => x*log2 = log n => x = logn/log2
    bool isPowerOfTwo(int n) {
        double x = log10(n)/log10(2);
        return (x-(int)x == 0)?true:false;
    }
};