/*
Check Palindrome!
Programming
Hashing
Easy
79.3% Success

142

5

Bookmark
Asked In:
Problem Description
 
 

Given a string A consisting of lowercase characters.

Check if characters of the given string can be rearranged to form a palindrome.

Return 1 if it is possible to rearrange the characters of the string A such that it becomes a palindrome else return 0.



Problem Constraints
1 <= |A| <= 105

A consists only of lower-case characters.



Input Format
First argument is an string A.



Output Format
Return 1 if it is possible to rearrange the characters of the string A such that it becomes a palindrome else return 0.



Example Input
Input 1:

 A = "abcde"
Input 2:

 A = "abbaee"


Example Output
Output 1:

 0
Output 2:

 1


Example Explanation
Explanation 1:

 No possible rearrangement to make the string palindrome.
Explanation 2:

 Given string "abbaee" can be rearranged to "aebbea" to form a palindrome.
*/

int Solution::solve(string A) {
    unordered_map<char, int> mp;
    
    for(int i = 0; i < A.length(); i++) {
        mp[A[i]]++;
    }
    
    int cnt = 0;
    for(auto m : mp) {
        if(m.second % 2 != 0) // Checking if the count is odd
            cnt++;
    }
    
    int n = mp.size();
    
    // Check if cnt is less than or equal to 1, indicating at most one character occurs an odd number of times
    return cnt <= 1 ? 1 : 0;
}
