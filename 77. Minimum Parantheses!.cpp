/*
Minimum Parantheses!
Programming
Strings
Easy
77.4% Success

180

4

Bookmark
Asked In:
Problem Description

Given a string A of parantheses  ‘(‘ or ‘)’.

The task is to find minimum number of parentheses ‘(‘ or ‘)’ (at any positions) we must add to make the resulting parentheses string valid.

An string is valid if:

Open brackets must be closed by the corresponding closing bracket.
Open brackets must be closed in the correct order.


Problem Constraints
1 <= |A| <= 105

A[i] = '(' or A[i] = ')'



Input Format
First and only argument is an string A.



Output Format
Return a single integer denoting the minimumnumber of parentheses ‘(‘ or ‘)’ (at any positions) we must add in A to make the resulting parentheses string valid.



Example Input
Input 1:

 A = "())"
Input 2:

 A = "((("


Example Output
Output 1:

 1
Output 2:

 3


Example Explanation
Explanation 1:

 One '(' is required at beginning.
Explanation 2:

 Three ')' is required at end.
*/

/*
Intuition:
- We iterate through the string from left to right.
- We maintain counts of open and close parentheses.
- If we encounter an opening parenthesis '(', we increment the open count.
- If we encounter a closing parenthesis ')' and there are still open parentheses, we decrement the open count.
- Otherwise, if there are no open parentheses to match the closing one, we increment the close count.
- At the end, the total number of unmatched parentheses is the sum of open and close counts.

Time Complexity: O(n), where n is the length of the input string.
- We iterate through the string once.

Space Complexity: O(1).
- We use only a constant amount of extra space for the variables.
*/

int Solution::solve(string A) {
    int open = 0, close = 0;
    
    // Process the string from left to right
    for (int i = 0; i < A.size(); i++) {
        if (A[i] == '(')
            open++;
        else if (open > 0)
            open--; // Match closing parenthesis with an open one
        else
            close++; // Unmatched closing parenthesis
    }
    
    return open + close; // Total number of unmatched parentheses
}
