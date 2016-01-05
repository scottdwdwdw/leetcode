/*
*
*  2.Rotate an array of n elements to the right by k steps.
     For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
*/

//�ҵĴ��룺 //��Ҫ����ռ䣬�㷨���Ӷ�Ϊo(n);
 void rotate(vector<int>& nums, int k) {
        auto n=nums.size();
        int temp=0;
        std::vector<int>res(n);
        int j=0;
        int i=0;
        k=k%n;
        if(k==0)return;
        for(i=n-k;i<n;++i)
        {
            res[j++]=nums[i];
        }
        for(i=0;i<(n-k);++i)
        {
            res[j++]=nums[i];
        }
        nums=std::move(res);
    }
/*
in place����

�����k������ô���ǰѺ���k���ŵ�ǰ���ˡ�

�����Ȱ���������reverse��Ȼ���ǰ���reverse�������ٰѺ����reverse����

 

����AB����Ҫͨ��reverse�����õ�BA

��ô�Ȱ�AB reverseһ�εõ�reverse(B)reverse(A)

Ȼ���ٰ�reverse(B),reverse(A)�ֱ�reverseһ�ξ͵õ���BA
*/
class Solution {
public:
    void rotate(int nums[], int n, int k) {
        k = k % n;
        reverse(nums, nums + n);  //���Ի��ɵ�����
        reverse(nums, nums + k);
        reverse(nums + k, nums + n);
    }
};

