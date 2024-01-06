/*
Stairs
Programming
Dynamic Programming
Easy
68.2% Success

188

6

Bookmark
Asked In:
You are climbing a stair case and it takes A steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?



Input Format:

The first and the only argument contains an integer A, the number of steps.
Output Format:

Return an integer, representing the number of ways to reach the top.
Constrains:

1 <= A <= 36
Example :

Input 1:

A = 2 Output 1:

2 Explanation 1:

[1, 1], [2] Input 2:

A = 3 Output 2:

3 Explanation 2: 

[1 1 1], [1 2], [2 1]
*/

int solve(int A, int dp[]) {
    if (A <= 3) return A;  // Base case: for A <= 2, return A
    // Each recursive call should have its own ans variable
    if (dp[A-1] != 0) return dp[A-1];
    int ans = solve(A - 1, dp) + solve(A - 2, dp);
    dp[A-1] = ans;
    return ans;
}

int Solution::climbStairs(int A) {
    // The initial value of ans should be 0
    int dp[A+1] = {0};
    return solve(A, dp);
}
