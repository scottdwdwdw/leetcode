/*
*
*	Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

*
*/
//˼·1��
 bool isPalindrome(string s) {
        //����ȥ���ո���
        auto it=s.begin();
        for(int i=0;i<s.size();)
        {
           if(s[i]==' '||ispunct(s[i]))
           {
               s.erase(it+i);  //ɾ���ո�ͱ�����
           }
           else ++i;
        }
        auto  n=s.size();
        if(n==0)return true;
        char*first=&s[0];
        char*second=&s[n-1];
        while(first<second)
        {
            if(tolower(*first)!=tolower(*second))return false;
            ++first;--second;
        }
        if(first>=second)return true;
        else return false;
    }
	
	
	
//ֱ�ӱȽ�
 bool isPalindrome(string s) {
           int l=0, r=s.size()-1;
    while (l<r) {
        while (l<r && !isalnum(s[l]))
            l++;
        while (l<r && !isalnum(s[r]))
            r--;
        if (tolower(s[l])!=tolower(s[r]))
            return false;
        l++;
        r--;
    }
    return true;
    }	