/*
Pangram Check
Programming
Time Complexity
Very Easy
67.4% Success

40

4

Bookmark
Asked In:
Problem Description
 
 

Given a sentence represented as an array A of strings that contains all lowercase alphabets.
Chech if it is a pangram or not.
A pangram is a unique sentence in which every letter of the lowercase alphabet is used at least once.


Problem Constraints
1 <= |A| <= 105
1 <= |Ai|<= 5


Input Format
Given an array of strings A.


Output Format
Return an integer.


Example Input
Input 1:
A = ["the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"]
Input 2:

A = ["bit", "scale"]




Example Output
Output 1:
1
Output 2:

0


Example Explanation
Explanation 1:
We can check that all english alphabets are present in given sentence.
Explanation 2:

Not all english alphabets are present.
*/

/*
Intuition:
This function checks whether all the 26 English lowercase letters (a to z) are present in the input vector of strings. It iterates over each character in each string and marks the corresponding index in the 'ans' vector as 1 if the character is encountered. After iterating through all strings, it checks if there are any indices in the 'ans' vector that are still 0, indicating that some characters are missing. If all characters are found, it returns 1, otherwise, it returns 0.

Time Complexity: O(N * M)
- N is the number of strings in the input vector A.
- M is the average length of the strings in A.
The function iterates over each character in each string, resulting in a time complexity proportional to the total number of characters in all strings.

Space Complexity: O(1)
The 'ans' vector is of constant size 26, independent of the input size. Hence, the space complexity is constant.
*/

int Solution::solve(vector<string> &A) {
    vector<int> ans(26, 0); // Initialize a vector to store presence of each letter (0 - absent, 1 - present)
    
    // Iterate over each string in the input vector
    for(string str : A) {
        // Iterate over each character in the string
        for(char ch : str) {
            ans[ch - 'a'] = 1; // Mark the presence of the character by setting the corresponding index to 1
        }
    }
    
    // Check if any character is missing (presence is still 0)
    for(int i = 0; i < 26; i++) {
        if(!ans[i])
            return 0; // Return 0 if any character is missing
    }
    
    return 1; // Return 1 if all characters are found
}
