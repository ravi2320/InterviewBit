/*
Longest Common Subsequence
Programming
Dynamic Programming
Easy
63.6% Success

308

9

Bookmark
Asked In:
Problem Description

Given two strings A and B. Find the longest common sequence ( A sequence which does not need to be contiguous), which is common in both the strings.

You need to return the length of such longest common subsequence.



Problem Constraints
1 <= |A|, |B| <= 1005



Input Format
First argument is an string A.

Second argument is an string B.



Output Format
Return the length of such longest common subsequence between string A and string B.



Example Input
Input 1:

 A = "abbcdgf"
 B = "bbadcgf"


Example Output
Output 1:

 5


Example Explanation
Explanation 1:

 The longest common subsequence is "bbcgf", which has a length of 5

*/

int Solution::solve(string A, string B) {
    int n = A.length();
    int m = B.length();
    vector<int> prev(m+1, 0), curr(m+1, 0);
    for(int j=0; j<=m; j++) prev[j] = 0;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(A[i-1] == B[j-1]) curr[j] = 1 + prev[j-1];
            else curr[j] = max(curr[j-1], prev[j]);
        }
        prev = curr;
    }
    return prev[m];
}
