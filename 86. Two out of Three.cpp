/*
Two out of Three
Programming
Hashing
Medium
46.7% Success

155

36

Bookmark
Asked In:
Problem Description

Given are Three arrays A, B and C.

Return the sorted list of numbers that are present in atleast 2 out of the 3 arrays.



Problem Constraints
1 <= |A|, |B|, |C| <= 100000

1 <= A[i], B[i], C[i] <= 100000

A, B, C may or may not have pairwise distinct elements.



Input Format
First argument is the array A.

First argument is the array B.

First argument is the array C.



Output Format
Return a sorted array of numbers.



Example Input
Input 1:

A = [1, 1, 2]
B = [2, 3]
C = [3]
Input 2:

A = [1, 2]
B = [1, 3]
C = [2, 3]


Example Output
Output 1:

[2, 3]
Output 2:

[1, 2, 3]


Example Explanation
Explanation 1:

1 is only present in A. 2 is present in A and B. 3 is present in B and C.
Explanation 2:

All numbers are present in atleast 2 out of 3 lists.


*/

// Intuition:
// This class provides a solution to find the common elements present in all three given vectors.
// It uses unordered sets to store unique elements from each vector and then counts the occurrence
// of each element using a map. Finally, it returns the elements that appear more than once.

// Time Complexity: O(n1 + n2 + n3), where n1, n2, and n3 are the sizes of vectors A, B, and C respectively.
// - The algorithm iterates through each vector once to populate the sets and maps, resulting in a linear time complexity.

// Space Complexity: O(n1 + n2 + n3)
// - The algorithm uses additional space to store unique elements in sets and counts their occurrences in the map.

#include <vector>
#include <unordered_set>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> solve(vector<int> &A, vector<int> &B, vector<int> &C) {
        // Create sets to store unique elements from each vector
        unordered_set<int> st1, st2, st3;
        for (int i = 0; i < A.size(); i++) {
            st1.insert(A[i]);
        }
        for (int i = 0; i < B.size(); i++) {
            st2.insert(B[i]);
        }
        for (int i = 0; i < C.size(); i++) {
            st3.insert(C[i]);
        }
        
        // Create a map to count occurrences of elements
        map<int, int> mp;
        for (int s : st1)
            mp[s]++;
        for (int s : st2)
            mp[s]++;
        for (int s : st3)
            mp[s]++;
        
        // Create a vector to store common elements that appear more than once
        vector<int> res;
        for (auto m : mp) {
            if (m.second > 1)
                res.push_back(m.first);
        }
        return res; // Return the common elements
    }
};

// Sample Usage
#include <iostream>
int main() {
    Solution obj;
    vector<int> A = {1, 2, 3, 4, 5};
    vector<int> B = {3, 4, 5, 6, 7};
    vector<int> C = {5, 6, 7, 8, 9};
    vector<int> result = obj.solve(A, B, C);
    cout << "Common elements in A, B, and C: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl; // Output: Common elements in A, B, and C: 5
    return 0;
}
