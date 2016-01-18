/*
*
*Implement atoi to convert a string to an integer.
*/
//我的实现
    int myAtoi(string str) {
        auto n=str.size();
        string res="";
        long long res_int=0;
        size_t i=0;
        bool neg=false;
        while(str[i]==' ')++i;
        if(str[i]=='-'){ neg=true;++i;}
        else if(str[i]=='+'){++i;}
        for(;i<n;++i)
        {
            if(str[i]>='0'&&str[i]<='9')
            {
                res.push_back(str[i]);
            }
            else break;
        }
        int n2=res.size();
        int j=(int)(n2-1);
        int k=0;
        if(j>9)return neg?INT_MIN:INT_MAX;
        for(;j>=0,k<n2;--j,++k)
        {
            int temp=res[k]-48;
            res_int+=temp*pow(10,j); 
            
        }
        res_int=neg?-res_int:res_int;
        if(res_int>=INT_MAX)res_int=INT_MAX ;
        else if(res_int<=INT_MIN)res_int=INT_MIN;
        return res_int;  
      }
	  
	  
	  
//
int myAtoi(string str) {
    if (str.empty()) return 0;
    int i = 0, sign = 1;
    while (i + 1 < str.size() && isspace(str[i])) ++i;
    long res = 0;
    if (str[i] == '-' || str[i] == '+') sign = 44 - str[i++];
    while (i < str.size()) {
        if (isdigit(str[i])) res = 10 * res + str[i++] - '0';
        else return res * sign;
        if (res > INT_MAX) return sign == -1 ? INT_MIN : INT_MAX;
    }
    return res * sign;
}