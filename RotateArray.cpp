/*
*
*  2.Rotate an array of n elements to the right by k steps.
     For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
*/

//我的代码： //需要额外空间，算法发杂度为o(n);
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
in place交换

如果是k步，那么就是把后面k个放到前面了。

我们先把整个数组reverse，然后把前面的reverse回来，再把后面的reverse回来

 

对于AB我们要通过reverse操作得到BA

那么先把AB reverse一次得到reverse(B)reverse(A)

然后再把reverse(B),reverse(A)分别reverse一次就得到了BA
*/
class Solution {
public:
    void rotate(int nums[], int n, int k) {
        k = k % n;
        reverse(nums, nums + n);  //可以换成迭代器
        reverse(nums, nums + k);
        reverse(nums + k, nums + n);
    }
};

