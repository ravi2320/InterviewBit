/*
Large Factorial
Programming
Arrays
Medium
38.7% Success

156

18

Bookmark
Asked In:
Problem Description

Given a number A. Find the fatorial of the number.



Problem Constraints
1 <= A <= 100



Input Format
First and only argument is the integer A.



Output Format
Return a string, the factorial of A.



Example Input
Input 1:

A = 2
Input 2:

A = 3


Example Output
Output 1:

 2
Output 2:

 6


Example Explanation
Explanation 1:

2! = 2 .
Explanation 2:

3! = 6 .
*/

string Solution::solve(int A) {
    vector<int> arr(1000, 0);
    string ans = "";

    arr[0] = 1;
    int carry;
    int temp;

    for (int n = 1; n <= A; n++) {
        carry = 0;
        for (int i = 0; i < 1000; i++) {
            temp = arr[i] * n + carry;
            arr[i] = temp % 10;
            carry = temp / 10;
        }
    }

    int i = 999;
    while (arr[i] == 0) {
        i--;
    }

    while (i >= 0) {
        ans += (char)(arr[i] + '0');  // Convert digit to character
        i--;
    }

    return ans;
}
