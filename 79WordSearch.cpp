/*
79. Word Search My Submissions QuestionEditorial Solution
Total Accepted: 75938 Total Submissions: 328235 Difficulty: Medium
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

class Solution {
public:

    /*row ,ѡ�����;
	  col ѡ�����;
	  row_max,������У�
	  col_max��������У�
	  n:�ַ�����
	  flag:��ǩ
	*/ 
    bool DFS(int row,int col,int n,int row_max,int col_max,vector<char>&ret_stack,vector<vector<char>>&board,string &word,int**flag)
    {
        bool ret = false;
        if(row<row_max&&col<col_max&&row>=0&&col>=0)
        {
            if(flag[row][col]==0&&board[row][col]==word[n])
            {
                if(n==word.size()-1)
                {
                    ret = true;
                    return ret;
                }
                ret_stack.push_back(word[n]);  //���Ԫ��
                flag[row][col]=1;
                //������һ�εĵ���
                if(!ret)ret = DFS(row+1,col,n+1,row_max,col_max,ret_stack,board,word,flag);//����
                if(!ret)ret = DFS(row,col+1,n+1,row_max,col_max,ret_stack,board,word,flag);//����
                if(!ret)ret = DFS(row,col-1,n+1,row_max,col_max,ret_stack,board,word,flag);//����
                if(!ret)ret = DFS(row-1,col,n+1,row_max,col_max,ret_stack,board,word,flag);//����
                 //��û���ҵ�
                if(!ret)
                {
                    ret_stack.pop_back();
                    flag[row][col]=0; //ȡ����־λ
                }
                
            }
            if(ret_stack.size()==0)  //�����ƶ�
            {
                if(col<col_max-1)ret = DFS(row,col+1,0,row_max,col_max,ret_stack,board,word,flag); //����
                else  //col==col_max-1
                {
                    ret = DFS(row+1,0,0,row_max,col_max,ret_stack,board,word,flag);
                }
                
            }
        }
        
        return ret;
    }
    //������ʾ��ʹ�û��ݷ�
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();      //��
        int n=board[0].size();   //��
        vector<char>ret_stack;
        int **flag=new int*[m];
        for(int i=0;i<m;i++)
        {
            flag[i] = new int[n]();
        }
        return DFS(0,0,0,m,n,ret_stack,board,word,flag);
    }
};