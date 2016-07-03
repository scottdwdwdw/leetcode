/*
290. Word Pattern My Submissions QuestionEditorial Solution
Total Accepted: 37761 Total Submissions: 127942 Difficulty: Easy
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.

Credits:
Special thanks to @minglotus6 for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

Show Tags
Show Similar Problems

*/

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int n = pattern.size();
        map<char,vector<int>>p;
        vector<string>sub;
        for(int i=0;i<n;++i)  //存储了相等的位置
        {
            p[pattern[i]].push_back(i);
        }
        
        //把str拆分
        int pos = 0;
        string sub_string;
        while(true)
        {
            int next_pos = str.find_first_of(' ',pos);
            if(next_pos == string::npos)next_pos = str.size(); 
            sub_string = str.substr(pos,next_pos-pos);
            sub.push_back(sub_string);
            if(next_pos == str.size())break;
            pos = next_pos+1;
        }
        if(pattern.size()!=sub.size())return false;
        set<int>different_val_index;
        for(int i=0;i<n;++i)
        {
           int j = p[pattern[i]][0];
           different_val_index.insert(j);
           string pre_string = sub[j];
            for(auto&e:p[pattern[i]])
            {
                if(sub[e]!=pre_string)return false;
            }
            
        }
        map<string,int>different_val_count;
        for(auto it=different_val_index.begin();it!=different_val_index.end();++it)
        {
            different_val_count[sub[*it]]+=1;
        }
        for(auto&e:different_val_count)
        {
            if(e.second>=2)return false;
        }
        
        return true;
    }
};

//使用istringstream是个不错的方法，比substr要快得多
bool wordPattern(string pattern, string str) {
    map<char, int> p2i;
    map<string, int> w2i;
    istringstream in(str);
    int i = 0, n = pattern.size();
    for (string word; in >> word; ++i) {
        if (i == n || p2i[pattern[i]] != w2i[word])
            return false;
        p2i[pattern[i]] = w2i[word] = i + 1;
    }
    return i == n;
}