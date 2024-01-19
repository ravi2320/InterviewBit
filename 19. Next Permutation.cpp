/*
Next Permutation
Programming
Arrays
Medium
28.7% Success

333

33

Bookmark
Asked In:
Problem Description
 
 

Implement the next permutation, which rearranges numbers into the numerically next greater permutation of numbers for a given array A of size N.

If such an arrangement is not possible, it must be rearranged in the lowest possible order i.e., sorted in ascending order.

Note:
The replacement must be in-place, do not allocate extra memory.
DO NOT USE LIBRARY FUNCTION FOR NEXT PERMUTATION. Use of Library functions will disqualify your submission retroactively and will give you penalty points.


Problem Constraints
1 <= N <= 5e5
1 <= A[i] <= 1e9


Input Format
The first and the only argument of input has an array of integers, A.


Output Format
Return an array of integers, representing the next permutation of the given array.


Example Input
Input 1:
    A = [1, 2, 3]
Input 2:
    A = [3, 2, 1]
Input 3:
    A = [1, 1, 5]
Input 4:
    A = [20, 50, 113]


Example Output
Output 1:
    [1, 3, 2]
Output 2:
    [1, 2, 3]
Output 3:
    [1, 5, 1]
Output 4:
    [20, 113, 50]
*/

vector<int> Solution::nextPermutation(vector<int> &A) {
    if(A.size() == 0) return A;
    int n = A.size();
    int idx = -1;
    for(int i=n-2; i>=0; i--){
        if(A[i] < A[i+1]){
            idx = i;
            break;
        }
    }
    if(idx != -1){
        for(int i=n-1; i > idx && idx != -1; i--){
            if(A[i] > A[idx]){
                swap(A[idx], A[i]);
                break;
            }
        }   
    }
    reverse(A.begin()+idx+1, A.end());
    return A;
}
