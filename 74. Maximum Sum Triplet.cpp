/*
Maximum Sum Triplet
Programming
Arrays
Medium
32.9% Success

698

64

Bookmark
Asked In:
Problem Description
 
 

Given an array A containing N integers.

You need to find the maximum sum of triplet ( Ai + Aj + Ak ) such that 0 <= i < j < k < N and Ai < Aj < Ak.

If no such triplet exist return 0.



Problem Constraints
3 <= N <= 105.

1 <= A[i] <= 108.



Input Format
First argument is an integer array A.



Output Format
Return a single integer denoting the maximum sum of triplet as described in the question.



Example Input
Input 1:

 A = [2, 5, 3, 1, 4, 9]
Input 2:

 A = [1, 2, 3]


Example Output
Output 1:

 16
Output 2:

 6


Example Explanation
Explanation 1:

 All possible triplets are:-
    2 3 4 => sum = 9
    2 5 9 => sum = 16
    2 3 9 => sum = 14
    3 4 9 => sum = 16
    1 4 9 => sum = 14
  Maximum sum = 16
Explanation 2:

 All possible triplets are:-
    1 2 3 => sum = 6
 Maximum sum = 6
*/

int Solution::solve(vector<int> &A) {
    int n = A.size();
    
    // Calculate suffix array
    vector<int> suffix(n);
    suffix[n - 1] = A[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suffix[i] = max(A[i], suffix[i + 1]);
    }
    
    // Calculate prefix set
    set<int> prefix;
    prefix.insert(A[0]);
    
    int res = 0;
    
    // Iterate through the elements of A
    for (int j = 1; j < n - 1; j++) {
        auto it = prefix.lower_bound(A[j]); // Find the lower bound of A[j] in the prefix set
        
        if (it != prefix.begin()) { // If A[j] has a lower element in the prefix set
            int Ai = *(--it); // Get the lower element
            int Ak = suffix[j + 1]; // Get the corresponding suffix element
            
            if (A[j] < Ak) { // If A[j] is less than the suffix element
                res = max(res, Ai + A[j] + Ak); // Update the result
            }
        }
        
        prefix.insert(A[j]); // Insert A[j] into the prefix set
    }
    
    return res; // Return the result
}