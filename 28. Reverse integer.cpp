/*
Reverse integer
Programming
Math
Easy
27.6% Success

156

131

Bookmark
Asked In:
Problem Description

You are given an integer N and the task is to reverse the digits of the given integer. Return 0 if the result overflows and does not fit in a 32 bit signed integer


Look at the example for clarification.



Problem Constraints
N belongs to the Integer limits.



Input Format
Input an Integer.



Output Format
Return a single integer denoting the reverse of the given integer.



Example Input
Input 1:

 x = 123


Input 2:

 x = -123


Example Output
Output 1:

 321


Ouput 2:

 -321


Example Explanation
 If the given integer is negative like -123 the output is also negative -321.
*/

int Solution::reverse(int A) {
    if(A > INT_MAX || A < INT_MIN) return 0;
    int n = A < 0 ? -(A) : A;
    int ans = 0; // Initialize ans to 0
    while(n > 0) {
        int rem = n % 10;
        if (ans > (INT_MAX - rem) / 10) return 0;
        ans = ans * 10 + rem;
        n /= 10;
    }
    return A < 0 ? -(ans) : ans;
}
