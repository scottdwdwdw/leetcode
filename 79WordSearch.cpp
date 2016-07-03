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

    /*row ,选择的行;
	  col 选择的列;
	  row_max,矩阵的行；
	  col_max：矩阵的列；
	  n:字符索引
	  flag:标签
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
                ret_stack.push_back(word[n]);  //添加元素
                flag[row][col]=1;
                //进行下一次的调用
                if(!ret)ret = DFS(row+1,col,n+1,row_max,col_max,ret_stack,board,word,flag);//向下
                if(!ret)ret = DFS(row,col+1,n+1,row_max,col_max,ret_stack,board,word,flag);//向右
                if(!ret)ret = DFS(row,col-1,n+1,row_max,col_max,ret_stack,board,word,flag);//向左
                if(!ret)ret = DFS(row-1,col,n+1,row_max,col_max,ret_stack,board,word,flag);//向上
                 //都没有找到
                if(!ret)
                {
                    ret_stack.pop_back();
                    flag[row][col]=0; //取消标志位
                }
                
            }
            if(ret_stack.size()==0)  //向下移动
            {
                if(col<col_max-1)ret = DFS(row,col+1,0,row_max,col_max,ret_stack,board,word,flag); //向右
                else  //col==col_max-1
                {
                    ret = DFS(row+1,0,0,row_max,col_max,ret_stack,board,word,flag);
                }
                
            }
        }
        
        return ret;
    }
    //根据提示，使用回溯法
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();      //行
        int n=board[0].size();   //列
        vector<char>ret_stack;
        int **flag=new int*[m];
        for(int i=0;i<m;i++)
        {
            flag[i] = new int[n]();
        }
        return DFS(0,0,0,m,n,ret_stack,board,word,flag);
    }
};