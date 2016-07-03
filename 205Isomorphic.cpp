/*
205. Isomorphic Strings My Submissions QuestionEditorial Solution
Total Accepted: 58340 Total Submissions: 194502 Difficulty: Easy
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.
*/

class Solution {
public:
   // 这道题与模式匹配的一样？
    bool isIsomorphic(string s, string t) {
        map<char,int>first;
        map<char,int>second;
        int n =s.size();
        for(int i=0;i<n;++i)
        {
            if(first[s[i]]!=second[t[i]])return false;
            first[s[i]] = i+1;
            second[t[i]] = i+1;
        }
        
        return true;
    }
};