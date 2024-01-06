/*
Longest Increasing Subsequence
Programming
Dynamic Programming
Medium
35.0% Success

299

18

Bookmark
Asked In:
Problem Description
 
 

Find the longest increasing subsequence of a given array of integers, A.

In other words, find a subsequence of array in which the subsequence's elements are in strictly increasing order, and in which the subsequence is as long as possible.

In this case, return the length of the longest increasing subsequence.



Problem Constraints
1 <= length(A) <= 2500

0 <= A[i] <= 2500



Input Format
The first and the only argument is an integer array A.



Output Format
Return an integer representing the length of the longest increasing subsequence.



Example Input
Input 1:

 A = [1, 2, 1, 5]
Input 2:

 A = [0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15]


Example Output
Output 1:

 3
Output 2:

 6
*/

int Solution::lis(const vector<int> &A) 
{
    int size = 0;
    int n = A.size();
    vector<int> tail(n);
    for(int x : A)
    {
        int start=0, end=size;
        while(start < end)
        {
            int mid = (start + end)/2;
            if(tail[mid] < x)
                start = mid + 1;
            else
                end = mid;
        }
        tail[start] = x;
        if(start == size) 
            size++;
    }
    return size;
}
