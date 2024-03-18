/*
Palindrome Integer
Programming
Math
Easy
49.3% Success

134

151

Bookmark
Asked In:
Problem Description
 
 

Determine whether an integer is a palindrome. Do this without extra space.

A palindrome integer is an integer x for which reverse(x) = x where reverse(x) is x with its digit reversed. Negative numbers are not palindromic.



Problem Constraints
INT_MIN <= A <= INT_MAX


Input Format
The first argument is an integer A.


Output Format
Return 1 if A is a Palindrome Integer else return 0.


Example Input
Input 1:
A = 12121
Input 2:
A = 123


Example Output
Output 1:
1
Output 2:
0


Example Explanation
Explanation 1:
 12121 when reversed will be 12121, and 12121 = 12121, hence a palindrome number.

Explanation 2:
 123 when reversed will be 321, and 123 != 321, hence not a palindrome number
*/

int Solution::isPalindrome(int A) {
    int x = A;
    long long ans = 0;
    while(A > 0){
        ans = ans * 10 + A % 10;
        A /= 10;
    }
    
    return x==ans ? 1:0;
}
