/*
*
*Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/
//˼·������ʹ������ָ����ָʾ�ȽϷ�Χ��Ҫע��߽�������������Ϊ"" ""��ʱ��
//�ҵĴ���:
int strStr(string haystack, string needle) {
        auto n = needle.size();
        auto n2=haystack.size();
        char*p1=&haystack[0];
        char*p2=&haystack[n]; 
        char*end=&haystack[n2];//β��ָ�룬���ܶ�ȡ��ֻ������־λ
        while(p2<=end)
        {
            char* temp_p=p1,*temp_p2=&needle[0];
            for(;temp_p<p2;++temp_p,++temp_p2)
            {
                if(*temp_p!=*temp_p2)break;
            }
            if(temp_p==p2)return (p1-&haystack[0]);
            else
            {
                ++p1;++p2;
            }
        }
        return -1;
    }


//KMP�㷨��

//ֱ�ӽ��
int strStr(string haystack, string needle) {
    for (int i = 0; i < (int)(haystack.size()-needle.size()+1); i++) {
        int j = 0;
        while (j < needle.size() && haystack[i+j] == needle[j])
            j++;
        if (j == needle.size()) 
            return i;
    }
    return -1;
}