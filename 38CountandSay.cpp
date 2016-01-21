/*
*
* The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.
*/
//ตÝน้
 string countAndSay(int n) {
        string res;
        if(n==1)
        {
            res="1";
        }
        else
        {
            string temp=countAndSay(n-1);
           char pre=temp[0];
            int count=1;
            int n=(int)temp.size();
            int i=0;
            while(i<n-1)
            {
                if(temp[i]==temp[i+1])++count;
                else
                {
                    res.push_back('0'+count);
                    res.push_back(temp[i]);
                    count=1;
                }
                ++i;
            }
            if(i==n-1)
            {
                  res.push_back('0'+count);
                  res.push_back(temp[i]);
            }
            
            
            return res;
        }
    }