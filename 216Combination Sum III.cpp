/*
216. Combination Sum III
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Ensure that numbers within the set are sorted in ascending order.


Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]
*/


//回溯法求解
class Solution {
public:
    void combinationSum_dispatch(int n,int&k,vector<int>&select_num,int*flag,vector<vector<int>>&res)
    {
        if(select_num.size()==k)//当搜索达到了预定个数，计算数据和
        {
            int sum_temp=0;
            for(int i=0;i<k;++i)
            {
                sum_temp+=select_num[i];
            }
            if(sum_temp == n)
            {
                res.push_back(select_num);
            }
            
            return;
        }
        else  //count < k
        {
           int i = select_num.size()?select_num.back()-1:0;
            for(;i<9;++i)
            {
                if(flag[i]==0)
                {
                    select_num.push_back(i+1);
                    flag[i] = 1;
                    combinationSum_dispatch(n,k,select_num,flag,res);
                    flag[i] = 0; //清除标识
                    select_num.pop_back();  //弹出 
                }
                
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
      //使用递归
      vector<vector<int>> res;   
      int*flag = new int[9]();
      vector<int>select_num;
      combinationSum_dispatch(n,k,select_num,flag,res);  
      return res;
    }