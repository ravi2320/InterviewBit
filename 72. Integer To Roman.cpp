/*
Integer To Roman
Programming
Strings
Medium
54.7% Success

206

13

Bookmark
Asked In:
Another question which belongs to the category of questions which are intentionally stated vaguely. 

Expectation is that you will ask for correct clarification or you will state your assumptions before you start coding.

Given an integer A, convert it to a roman numeral, and return a string corresponding to its roman numeral version

Note : This question has a lot of scope of clarification from the interviewer. Please take a moment to think of all the needed clarifications and see the expected response using “See Expected Output”

For the purpose of this question, https://projecteuler.net/about=roman_numerals has very detailed explanations.




Input Format

The only argument given is integer A.
Output Format

Return a string denoting roman numeral version of A.
Constraints

1 <= A <= 3999
For Example

Input 1:
    A = 5
Output 1:
    "V"

Input 2:
    A = 14
Output 2:
    "XIV"
*/

// Intuition:
// This function converts an integer A to its Roman numeral representation.
// It uses arrays of strings to represent the Roman numeral symbols for thousands, hundreds, tens, and ones places.
// By dividing the given number A into its corresponding digits and looking up the appropriate strings in the arrays,
// it constructs the Roman numeral representation.

// Time complexity: O(1)
// The function performs a constant number of operations regardless of the size of the input integer A.

// Space complexity: O(1)
// The function uses fixed-size arrays to store the Roman numeral symbols.
// The space required is independent of the size of the input integer A.

string Solution::intToRoman(int A) {
    // Arrays to store Roman numeral symbols for different digits
    string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    string M[] = {"", "M", "MM", "MMM"};
    
    // Construct the Roman numeral representation by concatenating strings
    return M[A/1000] + C[(A%1000)/100] + X[(A%100)/10] + I[(A%10)];
}
