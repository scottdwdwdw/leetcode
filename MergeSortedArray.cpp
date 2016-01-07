//Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
//我的代码
 void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>res(m+n);
        int i=0,j=0,count=0;
        while((i!=m)&&(j!=n))
        {
            if(nums1[i]<=nums2[j])
            {
                res[count]=nums1[i];
                ++i;
            }
            else
            {
                res[count]=nums2[j];
                ++j;
            }
            ++count;
        }
        if(i==m)
        {
            while(j!=n)
            {
                res[count++]=nums2[j++];
            }
        }
        else if(j==n)
        {
            while(i!=m)
            {
                res[count++]=nums1[i++];
            }
        }
        nums1=std::move(res);
    }

//推荐代码：
   void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i1 = m-1, i2 = n-1;
        while(i1>=0 && i2>=0) nums1[i1+i2+1] = nums1[i1]>nums2[i2]?nums1[i1--]:nums2[i2--];
        while(i2>=0) nums1[i2] = nums2[i2--];
    }

//高效代码
 for (int i = m + n - 1; i >= 0; i--)
        nums1[i] = m != 0 && (n == 0 || nums1[m - 1] > nums2[n - 1]) ? nums1[--m] : nums2[--n];