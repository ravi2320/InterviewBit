/*
First non-repeating character in a stream of characters
Programming
Stacks And Queues
Medium
34.6% Success

430

34

Bookmark
Asked In:
Problem Description

Given a string A denoting a stream of lowercase alphabets. You have to make new string B.

B is formed such that we have to find first non-repeating character each time a character is inserted to the stream and append it at the end to B. If no non-repeating character is found then append '#' at the end of B.



Problem Constraints
1 <= length of the string <= 100000



Input Format
The only argument given is string A.



Output Format
Return a string B after processing the stream of lowercase alphabets A.



Example Input
Input 1:

 A = "abadbc"
Input 2:

 A = "abcabc"


Example Output
Output 1:

 "aabbdd"
Output 2:

 "aaabc#"


Example Explanation
Explanation 1:

    "a"      -   first non repeating character 'a'
    "ab"     -   first non repeating character 'a'
    "aba"    -   first non repeating character 'b'
    "abad"   -   first non repeating character 'b'
    "abadb"  -   first non repeating character 'd'
    "abadbc" -   first non repeating character 'd'
Explanation 2:

    "a"      -   first non repeating character 'a'
    "ab"     -   first non repeating character 'a'
    "abc"    -   first non repeating character 'a'
    "abca"   -   first non repeating character 'b'
    "abcab"  -   first non repeating character 'c'
    "abcabc" -   no non repeating character so '#'
*/

// Intuition:
// This method finds the first non-repeating character in a string by using a queue and a visited array.
// It initializes a queue to store characters that have not been repeated.
// It also maintains a visited array to keep track of the status of each character: 0 for not visited, 1 for visited but not repeated, and 2 for repeated.
// It iterates through the string, updating the visited array and the queue accordingly.
// At each step, it checks if the front character of the queue is repeated. If it is, it pops it from the queue.
// Finally, it constructs the result string based on the front character of the queue (if it exists) or '#' if the queue is empty.

// Time Complexity: O(N)
// - N is the length of the input string A. The algorithm iterates through the string once.
// - Each character operation like pushing to the queue, popping from the queue, and updating the visited array takes constant time.

// Space Complexity: O(1) or O(26)
// - The algorithm uses a constant amount of extra space for the queue and visited array, regardless of the input size.
// - However, the visited array has a fixed size of 26 for lowercase letters, so technically the space complexity is O(26).
// - This is considered constant space since the size of the visited array does not depend on the input size.

#include <string>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // Function to find the first non-repeating character in a string
    string solve(string A) {
        string res;
        vector<int> visited(26, 0); // Initialize visited array for lowercase letters
        queue<int> q; // Initialize queue to store non-repeated characters

        // Iterate through the string
        for (int i = 0; i < A.size(); i++) {
            // Update visited array and queue based on current character
            if (visited[A[i] - 'a'] == 0) {
                visited[A[i] - 'a'] = 1;
                q.push(A[i]);
            } else {
                visited[A[i] - 'a'] = 2;
            }

            // Check if the front character of the queue is repeated, and if so, pop it
            while (!q.empty() && visited[q.front() - 'a'] == 2) {
                q.pop();
            }

            // Construct result string based on front character of the queue or '#' if the queue is empty
            if (!q.empty()) {
                res.push_back(q.front());
            } else {
                res.push_back('#');
            }
        }

        return res; // Return the result string
    }
};
