/*
*    Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
*   
*/


//我的代码
    int lengthOfLastWord(string s) {
        auto n=s.size();
        int word_begin=-1;
        int word_end=-1;
        string res="";
        for(int i=0;i<n;++i)
        {
            if(word_begin<0&&s[i]!=' ')
            {
                word_begin=i;
            }
            else if(word_begin>=0&&s[i]==' ')
            {
                word_end=i;
                res=s.substr(word_begin,word_end-word_begin);
                word_begin=-1;
                word_end=-1;
            }
        }
        if(word_begin>=0&&word_end<0)res=s.substr(word_begin);
        
        return res.size();
    }
	

	
//取巧的思路
    int lengthOfLastWord(string s) 
    {
        int lenOfLastWord = 0;
        int idx = s.size()-1;

        // skip whitespaces
        while(idx >= 0 && s[idx] == ' ')
            idx--;

        while(idx >= 0 && s[idx] != ' ')
        {
            idx--;
            lenOfLastWord++;
        }

        return lenOfLastWord;
    }