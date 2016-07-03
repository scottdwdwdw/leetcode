
/*
153. Find Minimum in Rotated Sorted Array   My Submissions QuestionEditorial Solution
Total Accepted: 91233 Total Submissions: 251280 Difficulty: Medium
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.

*/

class Solution {
public:

    //����һ����O(N)�ķ�����ʵ��
    int findMin_test(vector<int>& nums) {
        if(nums.size()<=1)return nums[0];
        int n = nums.size();
        for(int i=0;i<n-1;++i)
        {
            if(nums[i+1]<nums[i])return nums[i+1];
        }
        
        //û��
        return nums[0];
    }
    
    int binarySearch(int start,int end,vector<int>&nums)
    {
        int ret = 65535;
        while(start<=end)   //�߽�����,WTF
        {
            int mid = start+(end-start)/2;
            if(nums[start]<=nums[end])  //���Ǿ������ֵĲ��Һ��ҵ�����һ������������
            {
                return nums[start]<ret?nums[start]:ret;
            }
            if(nums[mid]>=nums[start])  //�м������߲��֣�������ұߵĻ����м�㲻���ܴ�����ߵ�ֵ
            {
                start = mid+1;
            }
            else                        //�м�����ұ߲���,�������
            {
                //nums[mid] < nums[start]
                ret = nums[mid];  //��¼�����С��ֵ
                end = mid-1;    //��Ϊ����mid+1�ˣ������п��ܻ�����Сֵ��������Ҫ���ȱ�����Сֵ
            }
        }
       
      
        return nums[start]<ret?nums[start]:ret;
    }
    
    //�����������ֲ��� log(n)
     int findMin(vector<int>& nums) 
     {
         return binarySearch(0,nums.size()-1,nums);
     }
};