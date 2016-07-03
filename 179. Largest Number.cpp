//179. Largest Number
/*Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.

Subscribe to see which companies asked this question
*/

/*思路：
  对数组进行排序，按照降序排，
  这里的一个关键点是，在排序时，不是单纯的判断哪个数字大，数字小，而是判断两个数字组合的顺序，如3,30,330的组合就比303的组合要大，所以3要在30的前面
*/

//但这样的解法时间很慢。

class Solution {
public:
    //
    string largestNumber(vector<int>& nums) {
      sort(nums.begin(),nums.end(),[](int a,int b){string temp = to_string(a)+to_string(b);string temp2=to_string(b)+to_string(a);return temp>temp2;});
      string res;
      
      if(nums[0]==0)
      {
          res="0";
      }
      else
      {
         for(auto&e:nums)
         {
          res+=to_string(e);
         }
      }
      
      
      return res;
    }
};

//这样能把时间提高到11ms
class Solution {
public:
    //
    string largestNumber(vector<int>& nums) {
      vector<string>sptr;
      for(int i = 0;i<nums.size();++i)
      {
          sptr.push_back(to_string(nums[i]));
      }
      sort(sptr.begin(),sptr.end(),[](string&a,string& b){return a+b>b+a;});
      string res;
      
      if(sptr[0][0]=='0')
      {
          res="0";
      }
      else
      {
         for(auto&e:sptr)
         {
          res+=e;
         }
      }
      
      
      return res;
    }
};