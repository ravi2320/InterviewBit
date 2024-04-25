/*
Distinct Numbers in Window
Programming
Heaps And Maps
Medium
55.3% Success

351

15

Bookmark
Asked In:
Problem Description

You are given an array of N integers, A1, A2 ,..., AN and an integer B. Return the of count of distinct numbers in all windows of size B.

Formally, return an array of size N-B+1 where i'th element in this array contains number of distinct elements in sequence Ai, Ai+1 ,..., Ai+B-1.

NOTE:  if B > N, return an empty array.



Input Format
First argument is an integer array A

Second argument is an integer B.



Output Format
Return an integer array.



Example Input
Input 1:

 A = [1, 2, 1, 3, 4, 3]
 B = 3
Input 2:

 A = [1, 1, 2, 2]
 B = 1


Example Output
Output 1:

 [2, 3, 3, 2]
Output 2:

 [1, 1, 1, 1]


Example Explanation
Explanation 1:

 A=[1, 2, 1, 3, 4, 3] and B = 3
 All windows of size B are
 [1, 2, 1]
 [2, 1, 3]
 [1, 3, 4]
 [3, 4, 3]
 So, we return an array [2, 3, 3, 2].
Explanation 2:

 Window size is 1, so the output array is [1, 1, 1, 1].
*/

// Intuition:
// This class provides a solution to find the number of distinct elements in each window of size 'B'
// in the given array 'A'. The algorithm uses a sliding window approach with a hashmap to efficiently
// count the distinct elements in each window.

// Time Complexity: O(n)
// - 'n' is the size of the input array 'A'.
// - The algorithm iterates through each element of the array once and performs constant-time operations
//   to update the hashmap and calculate the distinct elements in each window.

// Space Complexity: O(n)
// - The algorithm uses an additional hashmap to store the counts of distinct elements in each window.

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> dNums(vector<int> &A, int B) {
        int n = A.size();

        // Initialize the result vector with the correct size
        vector<int> ans(max(n - B + 1, 0), 0);

        // Handle edge cases
        if (B > n) return {};
        if (B == 1) return vector<int>(n, 1);

        // Initialize a hashmap to store the counts of distinct elements in each window
        unordered_map<int, int> mp;

        // Count distinct elements in the first window of size 'B'
        for (int i = 0; i < B; i++) {
            mp[A[i]]++;
        }

        // Calculate distinct elements in each subsequent window using the sliding window approach
        for (int i = B; i < n; i++) {
            ans[i - B] = mp.size();
            mp[A[i - B]]--;
            if (mp[A[i - B]] == 0)
                mp.erase(A[i - B]);
            mp[A[i]]++;
        }
        // Calculate distinct elements in the last window
        ans[n - B] = mp.size();
        return ans;
    }
};

// Sample Usage
#include <iostream>
#include <vector>
using namespace std;
int main() {
    Solution obj;
    vector<int> A = {1, 2, 1, 3, 4, 3};
    int B = 3;
    vector<int> result = obj.dNums(A, B);
    cout << "Distinct elements in each window of size " << B << ": ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl; // Output: Distinct elements in each window of size 3: 2 3 3 2
    return 0;
}
