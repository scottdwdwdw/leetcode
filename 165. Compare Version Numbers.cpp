/*
165. Compare Version Numbers My Submissions QuestionEditorial Solution
Total Accepted: 55859 Total Submissions: 313009 Difficulty: Easy
Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37
*/
class Solution {
public:
    //思路，按照'.'分割,依次迭代分割
    //最开始以为只有1.1 与1.0这样的版本号进行比较，后来发现还有1.0.0与1这样的版本号进行比较，所以
    //按照.来迭代分割，每分割依次，比较一次
    int SplitVersion(string&version)
    {
        int v=0;
        int pos = version.find_first_of('.');
        if(pos==string::npos)
        {
            v = stoi(version);
            version = "0";
        }
        else
        {
            v = stoi(version.substr(0,pos));
            version = version.substr(pos+1);
        }
        
        return v;
    }
    int dot_count(string version)
    {
        int count = 0;
        int pos = 0;
        while(version!="")
        {
           pos = version.find_first_of('.');
           if(pos!=string::npos)++count;
           else
           {
               break;
           }
           version = version.substr(pos+1);
        }
        
        return count;
    }
    int compareVersion(string version1, string version2) {
        int n1 = dot_count(version1);
        int n2 = dot_count(version2);
        int count = max(n1,n2);
        while(count>=0)
        {
            int v1 = SplitVersion(version1);
            int v2 = SplitVersion(version2);
            if(v1<v2)return -1;
            else if(v1>v2)return 1;
            --count;
        }
        
        return 0;
    }
};