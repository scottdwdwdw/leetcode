223. Rectangle Area My Submissions QuestionEditorial Solution
Total Accepted: 38427 Total Submissions: 127508 Difficulty: Easy
Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Rectangle Area
Assume that the total area is never beyond the maximum possible value of int.

class Solution {
public:
    //http://www.jianshu.com/p/59e841a8671c
    //这样考虑各种情况不全
    /*
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int width=0;
        int height =0;
        if(E>=A&&G<=C&&F>=B&&H<=D)
        {
            width = abs(G-E);
            height= abs(H-F);
        }
        else if(E<C&&E>=A&&F<D&&F>=B)
        {
            width = abs(E-C);
            if(H>=D)height = abs(D-F);
            else
            {
                height = abs(F-B);
            }
        }
        else if(G>A&&G<=C&&H>B&H<=D)
        {
            width = abs(G-A);
            if(F<=B)height=abs(H-B);
            else
            {
                height = abs(D-F);
            }
        }
        
        int s1 = abs(C-A)*abs(D-B);
        int s2 = abs(G-E)*abs(H-F);
        return s1+s2-width*height;
    }*/
    /*
     int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) 
     {
         int c1 = C>G?G:C;
         int c2 = E>A?E:A;
         
         long width = c1-c2;   //这里出错了，应该是溢出了
         if(width<=0)width=0;
         
         int c3 = H>D?D:H;
         int c4 = B>F?B:F;
         long height = c3-c4;
         if(height<=0)height=0;
          int s1 = (C-A)*(D-B);
          int s2 = (G-E)*(H-F);
          return c1-c2;
     }
    */
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
    {
    int x = min(G, C) > max(E, A) ? (min(G, C) - max(E, A)) : 0;
    int y = min(D, H) > max(B, F) ? (min(D, H) - max(B, F)) : 0;
    return (D - B) * (C - A) + (G - E) * (H - F) - x * y;
    }
};