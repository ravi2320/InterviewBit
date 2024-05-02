/*
Serialize
Programming
Strings
Medium
84.9% Success

69

27

Bookmark
Asked In:
Problem Description
 
 

You are given an array A of strings and we have to serialize it and return the serialized string.

Serialization: Scan each element in a string, calculate its length and append it with a string and a element separator or deliminator (the deliminator is ~). We append the length of the string so that we know the length of each element.

For example, for a string 'interviewbit', its serialized version would be 'interviewbit12~'.



Problem Constraints
1 <= |A| <= 1000
1 <= |Ai| <= 1000
Ai only contains lowercase english alphabets.


Input Format
The first argument A is the string array A.


Output Format
Return a single integer denoting the serialized string.


Example Input
Input 1:
A = ['scaler', 'academy']
Input 2:

A = ['interviewbit']


Example Output
Output 1:
scaler6~academy7~
Output 2:

interviewbit12~


Example Explanation
Explanation 1:
Length of 'scaler' is 6 and academy is 7. So, the resulting string is scaler6~academy7~.
Explanation 2:

Explained in the description above.
.
*/

// Intuition:
// This function serializes a vector of strings by concatenating each string with its length,
// followed by a delimiter '~'. This allows for easy deserialization by splitting the serialized string
// at the delimiter and extracting each substring along with its length.

// Time Complexity: O(N)
// - 'N' is the total number of characters in all strings combined.
// - The algorithm iterates through each string in the vector once.

// Space Complexity: O(N)
// - The serialized string 'ans' stores each string along with its length and the delimiter '~'.

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string serialize(vector<string>& A) {
        string ans = ""; // Initialize the serialized string
        
        // Iterate through each string in the vector
        for (string str : A) {
            ans += str + to_string(str.length()) + "~"; // Concatenate the string with its length and the delimiter '~'
        }
        
        return ans; // Return the serialized string
    }
};

// Sample Usage
#include <iostream>
int main() {
    Solution obj;
    vector<string> A = {"abc", "def", "ghi"};
    string serialized = obj.serialize(A);
    cout << "Serialized string: " << serialized << endl; // Output: Serialized string: abc3~def3~ghi3~
    return 0;
}
