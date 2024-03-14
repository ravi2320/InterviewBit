/*
Number of 1 Bits
Programming
Bit Manipulation
Easy
66.1% Success

265

11

Bookmark
Asked In:
Problem Description
 
 

Write a function that takes an integer and returns the number of 1 bits it has.


Problem Constraints
0 <= A <= 4294967295


Input Format
First and only argument contains integer A


Output Format
Return an integer as the answer


Example Input
Input1:
    11


Example Output
Output1:
3


Example Explanation
Explaination1:
11 is represented as 1101 in binary 
*/

int Solution::numSetBits(unsigned int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int cnt = 0;
    while(A > 0){
        if(A%2)
            cnt++;
        A = A/2;
    }
    return cnt;
}
