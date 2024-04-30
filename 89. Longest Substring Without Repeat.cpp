/*
Longest Substring Without Repeat
Programming
Hashing
Easy
30.4% Success

215

12

Bookmark
Asked In:
Problem Description
 
 

Given a string A, find the length of the longest substring without repeating characters.

Note: Users are expected to solve in O(N) time complexity.



Problem Constraints
1 <= size(A) <= 106

 String consists of lowerCase,upperCase characters and digits are also present in the string A.



Input Format
Single Argument representing string A.



Output Format
Return an integer denoting the maximum possible length of substring without repeating characters.



Example Input
Input 1:

 A = "abcabcbb"
Input 2:

 A = "AaaA"


Example Output
Output 1:

 3
Output 2:

 2


Example Explanation
Explanation 1:

 Substring "abc" is the longest substring without repeating characters in string A.
Explanation 2:

 Substring "Aa" or "aA" is the longest substring without repeating characters in string A.

*/

// Intuition:
// This function calculates the length of the longest substring without repeating characters.
// It uses a sliding window approach, where 'i' and 'j' are two pointers that define the current
// substring. The algorithm keeps track of the frequency of characters in the current window
// using a hashmap. It expands the window by moving 'j' to the right and updates the maximum
// length of the substring. If a character is repeated within the window, 'i' is moved to the
// right until there are no repeating characters in the window.

// Time Complexity: O(N)
// - 'N' is the length of the input string 'A'.
// - The algorithm iterates through each character of the string once.

// Space Complexity: O(N)
// - The algorithm uses a hashmap to store the frequency of characters in the current window.
// - In the worst case, the hashmap can contain all distinct characters in the string.

#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string A) {
        int i = 0, j = 0; // Initialize two pointers for the sliding window
        int n = A.size(); // Get the length of the input string
        unordered_map<char, int> mp; // Initialize a hashmap to store character frequencies
        int res = 0; // Initialize the result

        // Iterate through the string using the sliding window approach
        while (j < n) {
            char rightChar = A[j];
            mp[rightChar]++; // Increment the frequency of the character at index 'j'

            // Shrink the window by moving 'i' to the right until there are no repeating characters
            while (i < j && mp[rightChar] > 1) {
                char leftChar = A[i];
                mp[leftChar]--; // Decrement the frequency of the character at index 'i'
                if (mp[leftChar] == 0)
                    mp.erase(leftChar); // Remove the character from the hashmap if its frequency becomes zero
                i++; // Move 'i' to the right
            }

            // Update the maximum length of the substring
            res = max(res, j - i + 1);
            j++; // Move 'j' to the right to expand the window
        }

        // Return the length of the longest substring without repeating characters
        return res;
    }
};

// Sample Usage
#include <iostream>
int main() {
    Solution obj;
    string A = "abcabcbb";
    int length = obj.lengthOfLongestSubstring(A);
    cout << "Length of the longest substring without repeating characters: " << length << endl; // Output: Length of the longest substring without repeating characters: 3
    return 0;
}
