71. Simplify Path My Submissions QuestionEditorial Solution
Total Accepted: 53827 Total Submissions: 242073 Difficulty: Medium
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

class Solution {
public:
    //思路:
    //.:当前目录，..上一级目录
    //逻辑是什么？
    string simplifyPath(string path) {
        int n = path.size();
        vector<string>st;
        for(int i=0;i<n;)
        {
            if(path[i]=='/')
            {
                ++i;
                continue;
            }
            else
            {
                int j=i;
                while(path[j]!='/'&&j<n)++j;
                string dir = path.substr(i,j-i);
                if(dir=="..")
                {
                    if(st.size()>0)st.pop_back();
                }
                else if(dir!=".")
                {
                    st.push_back(dir);
                }
                
                i = j;
            }
        }
        string ret="/";
        for(int i=0;i<st.size();++i)
        {
            ret+=st[i];
            if(i!=st.size()-1)ret+="/";
        }
        return ret;
    }
};