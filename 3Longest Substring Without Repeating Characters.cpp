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

// �ҵķ����������˳�ʱ
class Solution {
public:
    //û���ظ�Ԫ�ص��������
    //two-pointer
    //����ָ�붼ָ���ַ�����ͷ������һ��ָ���ƶ����ж�����ָ�뷶Χ�������ظ�Ԫ�أ�����ޣ��洢����һ��ָ������ƶ��������
    //�ڶ���ָ���ƶ�
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
                res_temp[s[j]]++;    //���ַ�����ʱ�ˡ�
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
    //û���ظ�Ԫ�ص��������
    //two-pointer
    //����ָ�붼ָ���ַ�����ͷ������һ��ָ���ƶ����ж�����ָ�뷶Χ�������ظ�Ԫ�أ�����ޣ��洢����һ��ָ������ƶ��������
    //�ڶ���ָ���ƶ�
    //���ϵĽⷨ��
    //����ǰ�ַ����ֹ���ʱ���Ӵ���ʼλ��Ϊ��һ�θ��ַ����ֵ�λ�ã�������locs�����е�hashֵΪ��ǰλ�á�
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