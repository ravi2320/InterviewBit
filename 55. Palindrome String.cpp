/*
Palindrome String
Programming
Strings
Easy
34.0% Success

202

259

Bookmark
Problem Description
 
 

Given a string, determine if it is a palindrome. While checking for a palindrome, you have to ignore spaces, case, and all special characters; i.e. consider only alphanumeric characters.

Check the sample test case for reference.
Return 0 / 1 ( 0 for false, 1 for true ) for this problem


Problem Constraints
1 <= |A| <= 106


Input Format
The first argument is a string A.


Output Format
Return 0 / 1 ( 0 for false, 1 for true ) for this problem


Example Input
Input 1:
"A man, a plan, a canal: Panama"
Input 2:
"race a car"


Example Output
Output 1:
1
Output 2:
0


Example Explanation
Explanation 1:
The input string after ignoring spaces, and all special characters is "AmanaplanacanalPanama" 
which is a palindrome after ignoring the case.
Explanation 2:
The input string after ignoring spaces, and all special characters is "raceacar" which is not a palindrome
*/

int Solution::isPalindrome(string s) {
    int start = 0, end = s.length() - 1;
        while (start <= end) {
            if (!isalnum(s[start])) {
                start++;
            } else if (!isalnum(s[end])) {
                end--;
            } else {
                if (tolower(s[start]) == tolower(s[end])) {
                    start++;
                    end--;
                } else {
                    return 0;
                }
            }
        }
        return 1;
}
