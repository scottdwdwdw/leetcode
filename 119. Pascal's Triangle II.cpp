
/*
119. Pascal's Triangle II   My Submissions QuestionEditorial Solution
Total Accepted: 74934 Total Submissions: 231318 Difficulty: Easy
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

*/

class Solution {
public:
    //∏¥‘”∂» «o(n^2)
    vector<int> getRow(int rowIndex) {
      //  if(rowIndex==0)return vector<int>();
        vector<int>pre_array={1};
        vector<int>array_temp;
        for(int i=1;i<=rowIndex;++i)
        {
            array_temp.clear();
            array_temp.push_back(1);
            for(int j=0;j<pre_array.size()-1;++j)
            {
                array_temp.push_back(pre_array[j]+pre_array[j+1]);
            }
            array_temp.push_back(1);
            pre_array=array_temp;
        }
        
        return pre_array;
        
    }
};


class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> vi(rowIndex + 1);
        vi[0] = 1;
        for (int i = 0; i <= rowIndex ; ++i)    //∫‹«…√Ó
        {
            for (int j = i; j > 0; --j)
            {
                vi[j] = vi[j] + vi[j-1];
            }
        }
        return vi;
    }
};