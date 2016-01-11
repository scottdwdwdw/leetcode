/*
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/
//我的代码
 vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        digits[n-1]+=1;
        if((digits[n-1]%10)==0)
         {
            digits[n-1]=0;
            int j=n-2;
            for(;j>=0;--j)
            {
                digits[j]+=1;
                if((digits[j]%10)!=0)break;
                else
                {
                    digits[j]=0;
                }
            }
            if(j==-1) //溢出
            {
                digits[0]=1;
                digits.push_back(0);
            }
        }
        return digits;
    }