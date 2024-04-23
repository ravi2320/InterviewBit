/*
Segregate 0s and 1s in an array
Programming
Arrays
Medium
77.5% Success

110

15

Bookmark
Asked In:
Problem Description
 
 


You are given an array of 0s and 1s in random order. Segregate 0s on left side and 1s on right side of the array [Basically you have to sort the array]. Traverse array only once. 



Problem Constraints
1<=|A|<=1e6


Input Format
First argument is array of integers consisting of 0's and 1's only.


Output Format
Return a sorted array.


Example Input
Input 1:
a=[0 1 0]
Input 2:

A=[1 1 0 ]


Example Output
Ouput 1:
[0 0 1]
Ouput 2:

[0 1 1]


Example Explanation
Explanation 1:
 above is sorted array.
Explanation 2:

sort the array.
*/

// Intuition:
// This class provides a solution to sort an array containing only 0s and 1s in such a way
// that all 0s are placed before all 1s. It employs a two-pointer approach where one pointer
// starts from the beginning of the array and moves forward until it encounters a 1, and the
// other pointer starts from the end of the array and moves backward until it encounters a 0.
// Whenever these pointers find elements to be swapped, they exchange them, and the process continues
// until the pointers meet.

// Time Complexity: O(n)
// - 'n' is the size of the input array.
// - The algorithm iterates through the array once, and at each step, it performs constant-time operations.

// Space Complexity: O(1)
// - The algorithm uses only a constant amount of extra space for variables.

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> solve(vector<int> &arr) {
        int n = arr.size();

        int i = 0, j = n - 1;

        while (i < j) {

            // Move 'i' pointer until it encounters a 1
            while (arr[i] == 0 && i < j) {
                i++;
            }

            // Move 'j' pointer until it encounters a 0
            while (arr[j] == 1 && i < j)
                j--;

            // If 'i' pointer is still to the left of 'j' pointer, swap elements
            if (i < j) {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }

        return arr; // Return the sorted array
    }
};

// Sample Usage
#include <iostream>
int main() {
    Solution obj;
    vector<int> arr = {0, 1, 0, 1, 0, 0, 1, 1, 0};
    vector<int> result = obj.solve(arr);
    cout << "Sorted Array: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl; // Output: Sorted Array: 0 0 0 0 0 1 1 1 1
    return 0;
}
