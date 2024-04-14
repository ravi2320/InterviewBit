/*
K Largest Elements
Programming
Heaps And Maps
Easy
75.6% Success

160

3

Bookmark
Asked In:
Problem Description

Given an 1D integer array A of size N you have to find and return the B largest elements of the array A.

NOTE:

Return the largest B elements in any order you like.


Problem Constraints
1 <= N <= 105

1 <= B <= N

1 <= A[i] <= 103



Input Format
First argument is an 1D integer array A

Second argument is an integer B.



Output Format
Return a 1D array of size B denoting the B largest elements.



Example Input
Input 1:

 A = [11, 3, 4]
 B = 2
Input 2:

 A = [11, 3, 4, 6]
 B = 3


Example Output
Output 1:

 [11, 4]
Output 2:

 [4, 6, 11]


Example Explanation
Explanation 1:

 The two largest elements of A are 11 and 4
Explanation 2:

 The three largest elements of A are 11, 4 and 6
*/

// Intuition:
// We sort the given vector A in non-decreasing order using the greater<int>() comparator.
// This sorts A in descending order.
// Then, we create a new vector ans to store the first B elements from the sorted array A.
// Finally, we return the vector ans containing the first B largest elements of A.

// Time Complexity: O(N log N), where N is the size of the input vector A. 
//                   Sorting the vector takes O(N log N) time.
// Space Complexity: O(B), where B is the number of elements to return in the output vector ans.
vector<int> Solution::solve(vector<int> &A, int B) {
    // Sort the input vector A in descending order
    sort(A.begin(), A.end(), greater<int>());
    
    // Create a new vector to store the first B largest elements
    vector<int> ans;
    for (int i = 0; i < B; i++) {
        ans.push_back(A[i]); // Add the ith largest element to the ans vector
    }
    
    return ans; // Return the vector containing the first B largest elements
}
