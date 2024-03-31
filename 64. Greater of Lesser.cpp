/*
Greater of Lesser
Programming
Arrays
Very Easy
79.4% Success

42

35

Bookmark
Asked In:
Problem Description
 
 

Given two integer arrays A and B, and an integer C.
Find the number of integers in A which are greater than C and find the number of integers in B which are less than C.
Return maximum of these two values.


Problem Constraints
1 <= |A|, |B| <= 105
1 <= Ai, Bi, C <=109


Input Format
First argument is an integer array A.
Second argument is an integer array B.
Third argument is an integer C.


Output Format
Return an integer.


Example Input
Input 1:
A = [1, 2, 3, 4]
B = [5, 6, 7, 8]
C = 4
Input 2:

A = [1, 10, 100]
B = [9, 9, 9]
C = 50


Example Output
Output 1:
0
Output 2:

3


Example Explanation
Explanation 1:
There are no integers greater than C in A.
There are no integers less than C in B.
Explanation 2:

Integers greater than C in A are [100].
Integers less than C in A are [9, 9, 9].
*/

int Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int lesser = 0, greater = 0;
    int n = A.size(), m = B.size();
    for(int i=0; i<n; i++){
        lesser += (A[i] > C) ? 1 : 0;
    }
    
    for(int i=0; i<m; i++){
        greater += (B[i] < C) ? 1 : 0;
    }
    
    return max(lesser, greater);
}
