/*
*
*Write a function to find the longest common prefix string amongst an array of strings.
*/

//ÎÒµÄ´úÂë
string longestCommonPrefix(vector<string>& strs) {
        string res=strs.size()?strs[0]:"";
        int i=0;
        while(i<(int)(strs.size()-1))
        {
            int n=(strs[i].size()>strs[i+1].size())?strs[i+1].size():strs[i].size();
            int j=0;
            for(;j<n;++j)
            {
                if(strs[i][j]!=strs[i+1][j])break;
            }
            if(j<res.size())
            {
                if(j==0)res="";
                else res=res.substr(0,j);
            }
           
        
            ++i;
        }
        
        return res;
    }