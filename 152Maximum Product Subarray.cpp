/*
152. Maximum Product Subarray My Submissions QuestionEditorial Solution
Total Accepted: 59914 Total Submissions: 267992 Difficulty: Medium
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.

Subscribe to see which companies asked this question

*/

class Solution {
public:
    //ʹ�ö�̬�滮��
    //״̬ת�Ʒ��̣�
    // max_product[i] = max (max(max_product[i-1]*nums[i],min_product[i-1]*nums[i]),nums[i]);
    // min_product[i] = min(min(max_product[i-1]*nums[i],min_product[i-1]*nums[i]),nums[i]);
	//ע������״̬���̣�Ϊʲô�Ǻ�nums[i]�Ƚϴ�С����Ϊ��ĿҪ���Ǽ������ڵ����ĳ˻�
    // max_product[i]  ��ʾ��iΪ�����±������
    int maxProduct(vector<int>& nums) {
        int m = nums.size();
        vector<int>max_product(m,0);  //���ʵ���൱��һ������¼
        vector<int>min_product(m,0);
        max_product[0] = nums[0];
        min_product[0] = nums[0];
        int ans = nums[0];
        for(int i=1;i<m;++i)
        {
            int max_temp=0;
            int min_temp=0;
            if(nums[i]>0) //max_product[i] = max(max_product[i-1]*nums[i],nums[i])
            {
                max_temp = max(max_product[i-1]*nums[i],nums[i]);
                min_temp = min(min_product[i-1]*nums[i],nums[i]);
            }
            else if(nums[i]<0)
            {
                max_temp = max(min_product[i-1]*nums[i],nums[i]);
                min_temp = min(max_product[i-1]*nums[i],nums[i]);
            }
            
            max_product[i] = max_temp;
            min_product[i] = min_temp;
            
            ans = max(max_product[i],ans);
        }
        
        return ans;
    }
};