/*
48. Rotate Image My Submissions QuestionEditorial Solution
Total Accepted: 68324 Total Submissions: 196222 Difficulty: Medium
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?

Subscribe to see which companies asked this question

Show Tags

*/


//最基本的解法，o(n^2)的时间复杂度，o(n^2)的空间复杂度
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> ret = matrix;
        for(int i = 0;i<n;++i)
        {
            for(int j = 0;j<n;++j)
            {
                ret[j][n-i-1] = matrix[i][j]; 
            }
        }
        
        matrix = ret;
    }
};



//这是不开辟另外空间的方法
/*
 * clockwise rotate
 * first reverse up to down, then swap the symmetry 
 * 1 2 3     7 8 9     7 4 1
 * 4 5 6  => 4 5 6  => 8 5 2
 * 7 8 9     1 2 3     9 6 3
*/
void rotate(vector<vector<int> > &matrix) {
    reverse(matrix.begin(), matrix.end());
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = i + 1; j < matrix[i].size(); ++j)
            swap(matrix[i][j], matrix[j][i]);
    }
}
