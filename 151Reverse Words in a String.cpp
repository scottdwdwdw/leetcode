151. Reverse Words in a String My Submissions QuestionEditorial Solution
Total Accepted: 104595 Total Submissions: 665254 Difficulty: Medium
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.

click to show clarification.

Subscribe to see which companies asked this question

class Solution {
public:
    //将单词反转，用string 的find_last_of找到末尾的单词，存储
    //先整形，把左右两端的空格都去掉，如果存在的话
    void strip(string&s)
    {
        int pos = s.find_first_not_of(" ");
        if(pos!=string::npos)s = s.substr(pos);
        pos = s.find_last_not_of(" ");
        if(pos!=string::npos)s= s.substr(0,pos+1);
    }
    void reverseWords(string &s) {
        strip(s);
        string res_temp;
        while(s!="")
        {
            int pos = s.find_last_of(' ');
            if(pos==string::npos)
            {
                res_temp+=s;
                s="";
            }
            else
            {
                string word = s.substr(pos+1);
                res_temp+=word;
                s = s.substr(0,pos);
            }
            strip(s);
            res_temp+=" ";
        }
        int pos = res_temp.find_last_not_of(" ");
        if(pos==string::npos)res_temp = "";
        else
        {
            res_temp = res_temp.substr(0,pos+1);
        }
        s = res_temp;
    }
};

//o(n)solution time:o(n),space:o(n)
class Solution {
public:
    void reverseWords(string &s) {
        string result = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') continue;
            int pos = i;
            while (i < s.length() && s[i] != ' ') i++;
            if (result.length() > 0) result = ' ' + result;
            result = s.substr(pos, i - pos) + result;
            i--;
        }
        s = result;
    }
};