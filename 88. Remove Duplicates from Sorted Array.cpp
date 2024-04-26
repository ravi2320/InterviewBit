/*
Remove Duplicates from Sorted Array
Programming
Two Pointers
Easy
43.5% Success

259

148

Bookmark
Asked In:
Problem Description
 
 

Given a sorted array A consisting of duplicate elements.

Your task is to remove all the duplicates and return the length of the sorted array of distinct elements consisting of all distinct elements present in A.

Note: You need to update the elements of array A by removing all the duplicates

 



Problem Constraints
1 <= |A| <= 106
1 <= Ai <= 2 * 109


Input Format
First and only argurment containing the integer array A.



Output Format
Return a single integer, as per the problem given.


Example Input
Input 1:

A = [1, 1, 2]
Input 2:

A = [1, 2, 2, 3, 3]


Example Output
Output 1:

2
Output 2:

3


Example Explanation
Explanation 1:

Updated Array: [1, 2, X] after rearranging. Note that there could be any number in place of x since we dont need it.
We return 2 here.
Explanation 2:

Updated Array: [1, 2, 3, X, X] after rearranging duplicates of 2 and 3.
We return 3 from here.

*/

// Intuition:
// This function removes duplicates from a sorted array 'A' in-place by keeping two pointers,
// 'i' and 'j', where 'i' iterates through the array and 'j' points to the last unique element.
// If 'A[i]' is different from 'A[j]', it indicates a new unique element, which is then moved
// to the position after the last unique element.

// Time Complexity: O(n)
// - 'n' is the size of the input array 'A'.
// - The algorithm iterates through each element of the array once and performs constant-time operations.

// Space Complexity: O(1)
// - The algorithm uses only a constant amount of extra space for variables.

#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &A) {
        int j = 0; // Initialize pointer 'j' to track the last unique element

        // Iterate through the array 'A' starting from the second element
        for (int i = 1; i < A.size(); i++) {
            // If the current element is different from the last unique element,
            // move it to the position after the last unique element and update 'j'
            if (A[j] != A[i]) {
                j++;
                A[j] = A[i];
            }
        }

        // Return the size of the array after removing duplicates (last unique element index + 1)
        return j + 1;
    }
};

// Sample Usage
#include <iostream>
int main() {
    Solution obj;
    vector<int> A = {1, 1, 2, 2, 3, 4, 4, 5};
    int newSize = obj.removeDuplicates(A);
    cout << "New array size after removing duplicates: " << newSize << endl; // Output: New array size after removing duplicates: 5
    return 0;
}
