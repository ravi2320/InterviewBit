/*
Move Zeroes
Programming
Arrays
Medium
65.8% Success

172

4

Bookmark
Asked In:
Problem Description
 
 

Given an integer array A, move all 0's to the end of it while maintaining the relative order of the non-zero elements.


Note that you must do this in-place without making a copy of the array.



Problem Constraints
1 <= |A| <= 105


Input Format
First argument is array of integers A.


Output Format
Return an array of integers which satisfies above property.


Example Input
Input 1:
A = [0, 1, 0, 3, 12]
Input 2:

A = [0]


Example Output
Ouput 1:
[1, 3, 12, 0, 0]
Ouput 2:

[0]


Example Explanation
Explanation 1:
Shift all zeroes to the end.
Explanation 2:

There is only one zero so no need of shifting.
*/

// Intuition:
// This function moves all non-zero elements to the beginning of the input vector 'A' while maintaining their original order.
// It uses a two-pointer approach where one pointer 'i' iterates through the array,
// and another pointer 'j' keeps track of the position where the next non-zero element should be placed.
// When a non-zero element is encountered at index 'i', it is swapped with the element at index 'j'.
// Then, 'j' is incremented to move to the next position.

// Time Complexity: O(N)
// - 'N' is the size of the input vector 'A'.
// - The algorithm iterates through the array once.

// Space Complexity: O(1)
// - The algorithm uses constant extra space.

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> solve(vector<int> &A) {
        int j = 0; // Pointer to keep track of the position where the next non-zero element should be placed
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] != 0) {
                swap(A[i], A[j]); // Swap non-zero element with the element at position j
                j++; // Increment j to move to the next position
            }
        }
        return A; // Return the modified vector
    }
};

// Sample Usage
#include <iostream>
#include <vector>
int main() {
    Solution obj;
    vector<int> A = {0, 1, 0, 3, 12};
    vector<int> result = obj.solve(A);
    cout << "Modified vector: ";
    for (int num : result) {
        cout << num << " ";
    }
    // Output: Modified vector: 1 3 12 0 0
    return 0;
}
