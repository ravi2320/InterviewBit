/*
Length of Last Word
Programming
Strings
Easy
35.1% Success

176

130

Bookmark
Asked In:
Problem Description
 
 

Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Please make sure you try to solve this problem without using library functions. Make sure you only traverse the string once.



Problem Constraints
1 <= |A| <= 106


Input Format
The first argument is a string A


Output Format
Return an integer denoting the length of the last word in the string.


Example Input
Input 1:
A = " hello world "
Input 2:
A = "InterviewBit"


Example Output
Output 1:
5
Output 2:
12


Example Explanation
Explanation 1:
"world" is the last word of size 5
Explanation 2:
"InterviewBit" is the last word of size 12
*/

/*
Intuition:
- We start iterating from the end of the string.
- We encounter non-space characters, indicating the beginning of the last word. We start counting the length of this word.
- Once we encounter a space character after encountering non-space characters, we stop counting.
- We return the length of the last word.

Time Complexity: O(N)
- We iterate through the string once, so the time complexity is linear with respect to the length of the input string.

Space Complexity: O(1)
- We use only a constant amount of extra space for storing variables, so the space complexity is constant.
*/

int Solution::lengthOfLastWord(const string A) {
    bool count = false; // Flag to indicate if we are currently counting the length of the last word
    
    int lastWordLength = 0;
    
    for(int i = A.length() - 1; i >= 0; i--) {
        if(A[i] != ' ') {
            count = true; // Start counting the length of the last word
            lastWordLength++;
        } else if(count) {
            break; // Stop counting if we encounter a space after encountering non-space characters
        }
    }
    
    return lastWordLength;
}