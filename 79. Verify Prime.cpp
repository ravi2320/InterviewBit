/*
Verify Prime
Programming
Math
Easy
37.2% Success

109

11

Bookmark
Asked In:
Given a number N, verify if N is prime or not.

Return 1 if N is prime, else return 0.

Example :

Input : 7
Output : True
Problem Approach:

VIDEO : https://www.youtube.com/watch?v=7VPA-HjjUmU

Complete code in the hint.
*/

// Intuition:
// We check whether the given number A is prime or not.
// If A is less than 2, it's not a prime number, so we return 0.
// Otherwise, we iterate from 2 up to the square root of A.
// We check if A is divisible by any number in this range.
// If it is divisible by any number, then A is not a prime number, so we return 0.
// If A is not divisible by any number in this range, then it's a prime number, and we return 1.

// Time Complexity: O(sqrt(N)), where N is the value of A. We iterate up to the square root of A to check for divisibility.
// Space Complexity: O(1). We use only a constant amount of extra space for variables and temporary storage.
//                   The space complexity is independent of the value of A.
int Solution::isPrime(int A) {
    // If A is less than 2, it's not a prime number
    if (A < 2)
        return 0;
    
    // Check for divisibility from 2 up to the square root of A
    for (int i = 2; i <= sqrt(A); i += (i == 2 ? 1 : 2)) {
        // If A is divisible by i, it's not a prime number
        if (A % i == 0)
            return 0;
    }
    
    // A is a prime number
    return 1;
}
