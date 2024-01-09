/*
Min Sum Path in Matrix
Programming
Dynamic Programming
Medium
67.5% Success
131
5
Bookmark
Asked In:
Problem Description
 
 

Given a 2D integer array A of size M x N, you need to find a path from top left to bottom right which minimizes the sum of all numbers along its path.

NOTE: You can only move either down or right at any point in time. 



Input Format
First and only argument is an 2D integer array A of size M x N.



Output Format
Return a single integer denoting the minimum sum of a path from cell (1, 1) to cell (M, N).



Example Input
Input 1:

 A = [  [1, 3, 2]
        [4, 3, 1]
        [5, 6, 1]
     ]


Example Output
Output 1:

 8


Example Explanation
Explanation 1:

 The path is 1 -> 3 -> 2 -> 1 -> 1
 So ( 1 + 3 + 2 + 1 + 1) = 8


Note:You only need to implement the given function. Do not read input, instead use the arguments to the function. Do not print the output, instead return values as specified. Still have a question? Checkout Sample Codes for more details.
submission-count
38946
successful submissions.
*/

int Solution::minPathSum(vector<vector<int> > &A) {
    int n = A.size(), m = A[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0)); // Initialize a DP table to store minimum path sums

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0)
                dp[i][j] = A[i][j]; // If we are at the top-left corner, the minimum path sum is the value at (0, 0)
            else {
                // Calculate the minimum path sum considering moving up and moving left
                int up = A[i][j];
                if (i > 0)
                    up += dp[i - 1][j]; // Include the minimum path sum from above
                else
                    up += 1e9; // A large value if moving up is not possible (out of bounds)

                int left = A[i][j];
                if (j > 0)
                    left += dp[i][j - 1]; // Include the minimum path sum from the left
                else
                    left += 1e9; // A large value if moving left is not possible (out of bounds)

                // Store the minimum path sum in dp[i][j]
                dp[i][j] = min(up, left);
            }
        }
    }

    // The final result is stored in dp[n-1][m-1], which represents the destination
    return dp[n - 1][m - 1];
}
