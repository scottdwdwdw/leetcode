/*
204. Count Primes My Submissions QuestionEditorial Solution
Total Accepted: 64985 Total Submissions: 263625 Difficulty: Easy
Description:

Count the number of prime numbers less than a non-negative number, n.
*/

//这个解法会超时
class Solution {
public:
    bool isPrimes(int num)
    {
       for(int i=2;i*i<=num;++i)
       {
           if(num%i==0)return false;
       }
       return true;
    }
    int countPrimes(int n) {
        int prim_count=0;
        for(int i=2;i<n;++i)
        {
            if(isPrimes(i))++prim_count;
        }
        
        return prim_count;
    }
};

//官方解法   Sieve of Eratosthenes
class Solution {
public:
    int countPrimes(int n) {
        vector<int>isPrimeMark(n,1);
        int prim_count = 0;
        for(int i=2;i*i<n;++i)
        {
            if(!isPrimeMark[i])continue;
            for(int j=i*i;j<n;j+=i)
            {
                isPrimeMark[j]=0;
            }
        }
        
        for(int i=2;i<n;++i)
        {
            if(isPrimeMark[i])++prim_count;
        }
        return prim_count;
    }
};