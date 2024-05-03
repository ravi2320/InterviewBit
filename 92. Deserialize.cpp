/*
Deserialize
Programming
Strings
Medium
78.0% Success

45

10

Bookmark
Asked In:
Problem Description
 
 

You are given a string A which is a serialized string. You have to restore the original array of strings.

The string in the output array should only have lowercase english alphabets.

Serialization: Scan each element in a string, calculate its length and append it with a string and a element separator or deliminator (the deliminator is ~). We append the length of the string so that we know the length of each element.

For example, for a string 'interviewbit', its serialized version would be 'interviewbit12~'.



Problem Constraints
1 <= |A| <= 106


Input Format
The first argument is the string A.


Output Format
Return an array of strings which are deserialized.


Example Input
Input 1:
A = 'scaler6~academy7~'
Input 2:

A = 'interviewbit12~'


Example Output
Output 1:
['scaler', 'academy']
Output 2:

['interviewbit']


Example Explanation
Explanation 1:
Length of 'scaler' is 6 and academy is 7. So, the resulting string is scaler6~academy7~.
We hve to reverse the process.
Explanation 2:

Explained in the description above.
*/

// Intuition:
// This class provides a method to deserialize a string into a vector of strings.
// It iterates through the input string character by character.
// If the character is a lowercase letter (97 to 122 in ASCII), it appends it to the current string.
// If the character is not a lowercase letter and the current string is not empty, it adds the current string to the result vector and resets the current string.
// Finally, it returns the result vector containing deserialized strings.

// Time Complexity: O(N)
// - N is the length of the input string A.
// - The algorithm iterates through each character of the string once.

// Space Complexity: O(M)
// - M is the number of deserialized strings.
// - The space required is proportional to the number of deserialized strings.

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    // Function to deserialize the input string into a vector of strings
    vector<string> deserialize(string A) {
        vector<string> ans;
        string str = "";

        // Iterate through the input string
        for (int i = 0; i < A.size(); i++) {
            // If the character is a lowercase letter, append it to the current string
            if (A[i] >= 97 && A[i] <= 122)
                str += A[i];
            // If the character is not a lowercase letter and the current string is not empty, add the current string to the result vector and reset the current string
            else if (!str.empty()) {
                ans.push_back(str);
                str = "";
            }
        }

        return ans; // Return the vector of deserialized strings
    }
};
