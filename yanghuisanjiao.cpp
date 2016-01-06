/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]  
*/
  vector<vector<int>> generate(int numRows) {
        vector<int>row_tmp;
        vector<vector<int>>res;
        if(numRows==0)return res;
        row_tmp.push_back(1);
        res.push_back(row_tmp);
        if(numRows==1)return res;
        row_tmp.clear();
        row_tmp.push_back(1);
        row_tmp.push_back(1);
        res.push_back(row_tmp);
        if(numRows==2)return res;
        for(int j=2;j<numRows;++j)
        {
            int n=res[j-1].size();
            row_tmp.clear();
            row_tmp.push_back(1);
            for(int i=0;i<n-1;++i)
            {
                row_tmp.push_back(res[j-1][i]+res[j-1][i+1]);
            }
            row_tmp.push_back(1);
            res.push_back(row_tmp);
        }
        return res;
    }