/*
ARRAY_BUG
Programming
Arrays
Easy
64.8% Success

94

15

Bookmark
The following code is supposed to rotate the array A by B positions.

So, for example,


A : [1 2 3 4 5 6]
B : 1

The output :

[2 3 4 5 6 1]
However, there is a small bug in the problem. Fix the bug and submit the problem.
*/

vector<int> Solution::rotateArray(vector<int> &A, int B) {
    int n = A.size();
    B = B % n; // Calculate the effective number of rotations
    
    vector<int> ret(n); // Initialize the resultant vector with size n
    
    // Copy elements from A to ret with adjusted indices
    for (int i = 0; i < n; i++) {
        ret[i] = A[(i + B) % n];
    }
    
    return ret;
}