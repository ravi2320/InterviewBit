/*

Interleaving Strings
Programming
Dynamic Programming
Hard
40.5% Success

224

8

Bookmark
Asked In:
Given A, B, C, find whether C is formed by the interleaving of A and B.

Input Format:*

The first argument of input contains a string, A.
The second argument of input contains a string, B.
The third argument of input contains a string, C.
Output Format:

Return an integer, 0 or 1:
    => 0 : False
    => 1 : True
Constraints:

1 <= length(A), length(B), length(C) <= 150
Examples:

Input 1:
    A = "aabcc"
    B = "dbbca"
    C = "aadbbcbcac"

Output 1:
    1
    
Explanation 1:
    "aa" (from A) + "dbbc" (from B) + "bc" (from A) + "a" (from B) + "c" (from A)

Input 2:
    A = "aabcc"
    B = "dbbca"
    C = "aadbbbaccc"

Output 2:
    0

Explanation 2:
    It is not possible to get C by interleaving A and B.
*/

int Solution::isInterleave(string A, string B, string C) {
    
    if(A.size() + B.size() != C.size()) return 0;
    
    int dp[151][151];
    dp[0][0] = 1;
    
    for(int i=1; i<=A.size(); i++){
        if(A[i-1] != C[i-1]) dp[i][0] = 0;
        else dp[i][0] = dp[i-1][0];
    }

    for(int i=1; i<=B.size(); i++){
        if(B[i-1] != C[i-1]) dp[0][i] = 0;
        else dp[0][i] = dp[0][i-1];
    }
    
    for(int i=1; i<=A.size(); i++){
        for(int j=1; j<=B.size(); j++){
            if(A[i-1] == C[i+j-1] && dp[i-1][j])
                dp[i][j] = 1;
            else if(B[j-1] == C[i+j-1] && dp[i][j-1])
                dp[i][j] = 1;
            else dp[i][j] = 0;
        }
    }
    
    return dp[A.size()][B.size()];
}
