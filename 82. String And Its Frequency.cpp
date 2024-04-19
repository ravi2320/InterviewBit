/*
String And Its Frequency
Programming
Strings
Medium
78.1% Success

64

5

Bookmark
Asked In:
Problem Description
 
 

 Given a string A with lowercase english alphabets and you have to return a string in which, with each character its frequency is written in adjacent.



Problem Constraints
1 <= |A| <= 105


Input Format
First argument is the string A with lowercase english alphabets.


Output Format
Return a string in which each character frequency is written in adjacent.


Example Input
Input 1:
abbhuabcfghh
Input 2:

a


Example Output
Ouput 1:
a2b3h3u1c1f1g1
Ouput 2:

a1


Example Explanation
Explanation 1:
‘a’ occurs in the string a total of 2 times so we write a2 then ‘b’ occurs a total of 3 times so next we write b3 and so on
Explanation 2:

‘a’ occurs in the string a total of 1 time only.
*/


// Intuition:
// This class provides a solution to process a string to get a new string
// where each character is followed by its frequency count.

// Time Complexity: O(n)
// - 'n' is the length of the input string.
// - The algorithm iterates through the input string twice, once to calculate
//   the frequency of each character and once to construct the resulting string,
//   both of which take linear time.

// Space Complexity: O(1) (excluding the input string)
// - The algorithm uses a constant amount of extra space for the vector `mp`,
//   which stores the frequency of each character in the alphabet.

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to solve the given problem
    string solve(string A) {
        // Initialize a vector to store the frequency of each character
        vector<int> mp(26, 0);
        
        // Calculate the frequency of each character in the string
        for (char ch : A) {
            mp[ch - 'a']++;
        }
        
        // Initialize an empty string to store the result
        string ans = "";
        
        // Iterate through each character in the string
        for (char ch : A) {
            // If the frequency of the character is non-zero
            if (mp[ch - 'a']) {
                // Get the frequency of the character
                int freq = mp[ch - 'a'];
                
                // Append the character followed by its frequency to the result string
                ans += ch + to_string(freq);
                
                // Reset the frequency of the character to zero
                mp[ch - 'a'] = 0;
            }
        }
        
        // Return the resulting string
        return ans;
    }
};

// Sample Usage
#include <iostream>
int main() {
    Solution obj;
    string input = "aaabbc";
    cout << obj.solve(input) << endl; // Output: "a3b2c1"
    return 0;
}
