/*
299. Bulls and Cows My Submissions QuestionEditorial Solution
Total Accepted: 29781 Total Submissions: 99342 Difficulty: Easy
You are playing the following Bulls and Cows game with your friend: You write down a number and ask your friend to guess what the number is. Each time your friend makes a guess, you provide a hint that indicates how many digits in said guess match your secret number exactly in both digit and position (called "bulls") and how many digits match the secret number but locate in the wrong position (called "cows"). Your friend will use successive guesses and hints to eventually derive the secret number.

For example:

Secret number:  "1807"
Friend's guess: "7810"
Hint: 1 bull and 3 cows. (The bull is 8, the cows are 0, 1 and 7.)
Write a function to return a hint according to the secret number and friend's guess, use A to indicate the bulls and B to indicate the cows. In the above example, your function should return "1A3B".

Please note that both secret number and friend's guess may contain duplicate digits, for example:

Secret number:  "1123"
Friend's guess: "0111"
In this case, the 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow, and your function should return "1A1B".
You may assume that the secret number and your friend's guess only contain digits, and their lengths are always equal.

Credits:
Special thanks to @jeantimex for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

Show Tags

*/


//我这种解法是o(n^2)复杂度
class Solution {
public:
    string getHint(string secret, string guess) {
        int A_count=0;
        int B_count=0;
        
        //先判断相等位置是否是相同的值
        for(int i=0;i<guess.size();++i)
        {
            if(guess[i]==secret[i])
            {
               ++A_count;
               secret[i]='#';
               guess[i]='$';
            }
        }
        
        
        for(int i=0;i<guess.size();++i)
        {
            for(int j=0;j<secret.size();++j)
            {
                if(guess[i]==secret[j])
                {
                    ++B_count;
                    secret[j]='#';
                    break;
                }
            }
        }
 
        
        string res = to_string(A_count)+"A"+to_string(B_count)+"B";
        return res;
    }
};

//o(n)的解法
class Solution {
public:
    // only contains digits 
    string getHint(string secret, string guess) {
        int aCnt = 0;
        int bCnt = 0;
        vector<int> sVec(10, 0); // 0 ~ 9 for secret
        vector<int> gVec(10, 0); // 0 ~ 9 for guess 
        if (secret.size() != guess.size() || secret.empty()) { return "0A0B"; }
        for (int i = 0; i < secret.size(); ++i) {
            char c1 = secret[i]; char c2 = guess[i];
            if (c1 == c2) {
                ++aCnt; 
            } else {
                ++sVec[c1-'0'];
                ++gVec[c2-'0'];
            }
        }
        // count b 
        for (int i = 0; i < sVec.size(); ++i) {
            bCnt += min(sVec[i], gVec[i]);
        }
        return to_string(aCnt) + 'A' + to_string(bCnt) + 'B';
    }
};