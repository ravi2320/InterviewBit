/*
Positive Negative
Programming
Arrays
Very Easy
85.2% Success

38

5

Bookmark
Asked In:
Problem Description
 
 

Given an integer array A.
Find the number of positive and negative integers in it an return them in an array.


Problem Constraints
1 <= |A| <= 105
-109 <= Ai <= 109


Input Format
Given an integer array A.


Output Format
Return an integer array of length two, first value should be count of positive integers and other count of negative integers.


Example Input
Input 1:
A = [1, 2, 3]
Input 2:

A = [1, 0, -1]


Example Output
Output 1:
[3, 0]
Output 2:

[1, 1]


Example Explanation
Explanation 1:
Positive values are [1, 2, 3].
There are no negative values.
Explanation 2:

Only positive value is [1].
Only negative value is [-1].
*/

vector<int> Solution::solve(vector<int> &A) {
    int pos = 0, neg = 0;
    for(int i=0; i<A.size(); i++){
        if(A[i] < 0)
            neg++;
        else if(A[i] > 0)
            pos++;
    }
    return {pos, neg};
}
