/*
187. Repeated DNA Sequences My Submissions QuestionEditorial Solution
Total Accepted: 44683 Total Submissions: 173139 Difficulty: Medium
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].
*/

class Solution {
public:
    //第一种方法:给A,C,G,T编码。
    //A:001    C:011    G:111    T:100
    //只有10位，用int就可以表示
    vector<string> findRepeatedDnaSequences(string s) {
        map<int,int>record;
        vector<string>res;
        int n = s.size();
        int key = 0;
        for(int i=0;i<10;++i)
        {
            key = ((key<<3)|s[i]&0x7)&0x3fffffff;
        }
        record[key]++;
        for(int i=10;i<n;++i)
        {
            key = ((key<<3)|s[i]&0x7)&0x3fffffff;
            if(record[key]==1)
            {
                res.push_back(s.substr(i-9,10));
            }
            record[key]++;
        }
        
        return res;
    }
};