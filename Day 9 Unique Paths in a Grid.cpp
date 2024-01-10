/*
Unique Paths in a Grid
Programming
Dynamic Programming
Medium
35.6% Success
158
10
Bookmark
Asked In:
Given a grid of size m * n, lets assume you are starting at (1,1) and your goal is to reach (m,n). At any instance, if you are on (x,y), you can either go to (x, y + 1) or (x + 1, y).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Example :

There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/

int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();

    if (A[0][0] == 1 || A[n - 1][m - 1] == 1) return 0;
    vector<int> prev(m);
    for(int i=0; i<m; i++)
    {
        if(A[0][i] == 1) break;
        prev[i] = 1;   
    }
    

    for (int i = 1; i < n; i++) {
        vector<int> curr(m, 0);
        if(prev[0] == 1 && A[i][0] == 0) curr[0] = 1;
        for (int j = 1; j < m; j++) {
            if (A[i][j] != 1) {
                curr[j] = prev[j] + curr[j - 1];
            }
        }
        prev = curr;
    }

    return prev[m - 1];
}
