/*
36. Valid Sudoku My Submissions QuestionEditorial Solution
Total Accepted: 75414 Total Submissions: 243670 Difficulty: Easy
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.
*/

//

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        //�м��
        map<char,int>flag;
        for(int i=0;i<m;++i)
        {
            flag.clear();
            for(int j=0;j<n;++j)
            {
                if(board[i][j]!='.'&&flag[board[i][j]]!=0)return false;
                else
                {
                    flag[board[i][j]]=1;
                }
            }
        }
        //�м��
        
        for(int i=0;i<n;++i)
        {
            flag.clear();
            for(int j=0;j<m;++j)
            {
                if(board[j][i]!='.'&&flag[board[j][i]]!=0)return false;
                else
                {
                    flag[board[j][i]]=1;
                }
            }
        }
        //�Ź�����
        
        int q = m/3;
        int r = n/3;
        for(int i=0;i<q;++i)
        {
            for(int j=0;j<r;++j)
            {
                flag.clear();
                for(int k=0;k<3;++k)
                {
                    for(int l=0;l<3;++l)
                    {
                        if(board[i*3+k][j*3+l]!='.'&&flag[board[i*3+k][j*3+l]]!=0)return false;
                        else
                        {
                            flag[board[i*3+k][j*3+l]]=1;
                        }
                    }
                }
                
            }
        }
        
        return true;
        
    }
};