/*
11. Container With Most Water   My Submissions QuestionEditorial Solution
Total Accepted: 78003 Total Submissions: 224662 Difficulty: Medium
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.

Subscribe to see which companies asked this question
*/

//��ͼ��⣬ʵ���������������������˿�ʼ���м������������ߵ�ֵ���ұߵ�ֵ����ô�ƶ��ұ����ꣻ����ұߵ�ֵ����ߵ�ֵ����ô�ƶ���ߵ�ֵ��

/*      
        |       |
	    |   |   |
	 |  |   |   |
	 1  2   3   4
*/	 
class Solution {
public:
    int maxArea(vector<int>& height) {
       if(height.size()<=1)return 0;
       int left = 0;
       int right = height.size()-1;
       int max_vol=-1;
       int temp=-1;
       int val = -1;
       while(left<right)
       {
           temp = height[left]>height[right]?height[right]:height[left];
           val =  temp*(right-left);
           if(val>max_vol)max_vol = val;
          /* if(height[left]<height[right])++left;
           else 
           {
               --right;
           }*/
           if(height[left]<height[right])
           {
               int old_left = height[left];
               while(height[left]<=old_left&&left<right)++left;
           }
           else 
           {    
               int old_right = height[right];
               while(height[right]<=old_right&&left<right)--right;
           }
       }
       
       
       return max_vol;
    }
};


