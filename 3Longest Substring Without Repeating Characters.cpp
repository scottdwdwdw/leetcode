/*
3. Longest Substring Without Repeating Characters My Submissions QuestionEditorial Solution
Total Accepted: 153331 Total Submissions: 688821 Difficulty: Medium
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

Subscribe to see which companies asked this question
*/

// 我的方法，导致了超时
class Solution {
public:
    //没有重复元素的最长子序列
    //two-pointer
    //两个指针都指向字符串开头，其中一个指针移动，判断两个指针范围内有无重复元素，如果无，存储，第一个指针继续移动，如果有
    //第二个指针移动
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int pos1 = 0;
        int pos2 = 0;
        map<char,int>res_temp;
        int max_length = 0;
        while(pos2<n)
        {
            res_temp.clear();
            int j=pos1;
            for(;j<=pos2;++j)
            {
                res_temp[s[j]]++;    //这种方法超时了。
                if(res_temp[s[j]]>=2)break;
            }
            if(j==pos2+1)
            {
                if((pos2-pos1+1)>max_length)max_length = pos2-pos1+1;
                pos2++;
            }
            else
            {
               pos1++;
            }
            while(pos2-pos1+1<=max_length)
            {
                pos2++;
            }
        }
        return max_length;
    }
};


class Solution {
public:
    //没有重复元素的最长子序列
    //two-pointer
    //两个指针都指向字符串开头，其中一个指针移动，判断两个指针范围内有无重复元素，如果无，存储，第一个指针继续移动，如果有
    //第二个指针移动
    //网上的解法：
    //当当前字符出现过的时候，子串开始位置为上一次该字符出现的位置，并更新locs数组中的hash值为当前位置。
    int lengthOfLongestSubstring(string s) {
        vector<int>locs(256,-1);
        int pos1 = -1;
        int pos2 = 0;
        int max_length = 0;
        int n = s.size();
        for(int i=0;i<n;++i)
        {
            if(locs[s[i]]>pos1)
            {
                pos1 = locs[s[i]];
            }
            if(i-pos1>max_length)
            {
                max_length = i-pos1;
            }
            locs[s[i]] = i;
        }
        
        return max_length;
    }
      
};