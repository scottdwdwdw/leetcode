/*
*
*The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

//题意的理解，以及注意边界条件
//我的代码
string convert(string s, int numRows) {
        vector<string>resTemp(numRows);
        string res;
        auto n=s.size();
        for(size_t i=0;i<n;)
        {
            for(int j=0;j<numRows&&i<n;++j)
            {
                resTemp[j].push_back(s[i++]);
            }
            for(int j=numRows-2;j>0&&i<n;--j)
            {
                resTemp[j].push_back(s[i++]);
            }
        }
        for(int i=0;i<numRows;++i)
        {
            res+=resTemp[i];
        }
        
        return res;
    }
	
//

   bool isValid(string s) {
        stack<char> st;
        for(auto c : s){
            if(c == '(' || c == '{' || c == '[') st.push(c);
            else if(st.size() > 0){
                if(c == ')' && st.top() == '(') st.pop();
                else if (c == '}' && st.top() == '{') st.pop();
                else if (c == ']' && st.top() == '[') st.pop();
                else return false;
            } else return false;
        }
        return st.size() == 0;
    }
};