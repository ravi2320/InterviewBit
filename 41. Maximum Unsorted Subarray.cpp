/*
Maximum Unsorted Subarray
Programming
Arrays
Medium
23.9% Success

279

25

Bookmark
Asked In:
Problem Description
 
 

Given an array A of non-negative integers of size N. Find the minimum sub-array Al, Al+1 ,..., Ar such that if we sort(in ascending order) that sub-array, then the whole array should get sorted.
If A is already sorted, output -1.



Problem Constraints
1 <= N <= 1000000

1 <= A[i] <= 1000000



Input Format
First and only argument is an array of non-negative integers of size N.



Output Format
Return an array of length two where the first element denotes the starting index(0-based) and the second element denotes the ending index(0-based) of the sub-array. If the array is already sorted, return an array containing only one element i.e. -1.



Example Input
Input 1:

A = [1, 3, 2, 4, 5]
Input 2:

A = [1, 2, 3, 4, 5]


Example Output
Output 1:

[1, 2]
Output 2:

[-1]


Example Explanation
Explanation 1:

If we sort the sub-array A1, A2, then the whole array A gets sorted.
Explanation 2:

A is already sorted.
*/

vector<int> Solution::subUnsort(vector<int> &A) {
    int n = A.size();
    int start = -1, end = -1;
    
    for(int i=0; i<n-1; i++){
        if(A[i] > A[i+1]){
            start = i;
            break;
        }
    }
    
    if(start == -1) return {-1};
    
    for(int j = n-1; j > 0; j--){
        if(A[j] < A[j-1]){
            end = j;
            break;
        }
    }
    
    int minVal = INT_MAX, maxVal = INT_MIN;
    for(int i=start; i<=end; i++){
        minVal = min(A[i], minVal);
        maxVal = max(A[i], maxVal);
    }
    
    while(start > 0 && A[start - 1] > minVal){
        start--;
    }
    
    while(end < n - 1 && A[end + 1] < maxVal){
        end++;
    }
    
    return {start, end};
}
