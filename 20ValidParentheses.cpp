/*
*Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

//使用栈来完成
 bool isValid(string s) {
        std::stack<char>ParentTemp;
        size_t n=s.size();
        for(size_t i=0;i<n;)
        {
            string s_temp=s.substr(i,i+2);
            if(s_temp!="()"||s_temp!="[]"||s_temp!="{}") //需要将元素入栈
            {
                if(s[i]==')'||s[i]=='}'||s[i]==']')
                {
                    if(ParentTemp.empty())return false;
                    else
                    {
                        auto temp=ParentTemp.top();
                        
                        if(s[i]==')'&&temp!='(')return false;
                        else if(s[i]==']'&&temp!='[')return false;
                        else if(s[i]=='}'&&temp!='{')return false;
                        else 
                            ParentTemp.pop();  //弹栈
                    }
                }
                else
                {
                   ParentTemp.push(s[i]);
                }
                ++i;
            }
            else
            {
                i+=2;
            }
        }
        if(!ParentTemp.empty())return false;
    
        return true;
    }