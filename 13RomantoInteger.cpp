/*
*
*Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/

//
int romanToInt(string s) {
        int res=0;
        int num_tmp=0;
        int old_tmp=0;
        for(int i=0;i<s.size();++i)
        {
            
            switch(s[i])
            {
                case 'I':num_tmp=1;break;
                case 'X':num_tmp=10;break;
                case 'C':num_tmp=100;break;
                case 'M':num_tmp=1000;break;
                case 'V':num_tmp=5;break;
                case 'L':num_tmp=50;break;
                case 'D':num_tmp=500;break; 
            }
            if(i!=0&&old_tmp<num_tmp)
            {
                res=res-2*old_tmp;
            }
            res+=num_tmp;
            old_tmp=num_tmp;
        }
        
        return res;  
    }