/*
Roman To Integer
Programming
Strings
Medium
68.1% Success

180

4

Bookmark
Asked In:
Given a string A representing a roman numeral.

Convert A into integer.

A is guaranteed to be within the range from 1 to 3999.

NOTE: Read more 

details about roman numerals at Roman Numeric System




Input Format

The only argument given is string A.
Output Format

Return an integer which is the integer verison of roman numeral string.
For Example

Input 1:
    A = "XIV"
Output 1:
    14

Input 2:
    A = "XX"
Output 2:
    20
*/

// Intuition:
// We iterate through the Roman numeral string from left to right.
// We keep track of the previous and current Roman numeral values.
// If the current value is greater than the previous value, it means that it is part of a subtraction case.
// In such cases, we subtract twice the value of the previous Roman numeral from the total.
// Finally, we return the total sum of all Roman numeral values.

// Time complexity: O(n), where n is the length of the input string A.
// Space complexity: O(1) since we are using a constant amount of extra space.
int Solution::romanToInt(string A) {
    
    // Initialize variables to store the total sum, previous Roman numeral value, and current Roman numeral value
    int ans = 0;
    int prev = 0; 
    int curr = 0;
    
    // Length of the input Roman numeral string
    int n = A.length();
    
    // Iterate through the Roman numeral string
    for(int i = 0; i < n; i++){
        
        // Store the current value as the previous value before updating it
        prev = curr;
        
        // Determine the value of the current Roman numeral character
        if(A[i] == 'I')
            curr = 1;
        else if(A[i] == 'V')
            curr = 5;
        else if(A[i] == 'X')
            curr = 10;
        else if(A[i] == 'L')
            curr = 50;
        else if(A[i] == 'C')
            curr = 100;
        else if(A[i] == 'D')
            curr = 500;
        else if(A[i] == 'M')
            curr = 1000;
            
        // Add the current value to the total sum
        ans += curr;
        
        // Check if the current value is greater than the previous value (indicating a subtraction case)
        if(prev < curr)
            ans -= 2 * prev; // Subtract twice the previous value from the total
    }
    
    // Return the total sum of Roman numeral values
    return ans;
}
