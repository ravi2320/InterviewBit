/*
Find Nth Fibonacci
Programming
Math
Hard
23.7% Success

328

56

Bookmark
Asked In:
Problem Description

Given an integer A you need to find the Ath fibonacci number modulo 109 + 7.

The first fibonacci number F1 = 1

The first fibonacci number F2 = 1

The nth fibonacci number Fn = Fn-1 + Fn-2 (n > 2)



Problem Constraints
1 <= A <= 109.



Input Format
First argument is an integer A.



Output Format
Return a single integer denoting Ath fibonacci number modulo 109 + 7.



Example Input
Input 1:

 A = 4
Input 2:

 A = 3


Example Output
Output 1:

 3
Output 2:

 2


Example Explanation
Explanation 1:

 F3 = F2 + F1 = 1 + 1 = 2
 F4 = F3 + F2 = 2 + 1 = 3
Explanation 2:

 F3 = F2 + F1 = 1 + 1 = 2

*/

// Intuition:
// This class provides a solution to find the nth Fibonacci number using matrix exponentiation.
// It represents the Fibonacci sequence as a matrix and calculates its power using exponentiation by squaring.

// Time Complexity: O(log(n))
// - 'n' is the input integer.
// - The algorithm performs matrix exponentiation in O(log(n)) time using exponentiation by squaring.

// Space Complexity: O(1)
// - The algorithm uses only a constant amount of extra space for variables.

#include <vector>
using namespace std;

const int mod = 1000000007;

// Function to multiply two matrices
vector<vector<long long>> multiply(const vector<vector<long long>>& A, const vector<vector<long long>>& B) {
    int n = A.size();
    vector<vector<long long>> C(n, vector<long long>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                // Perform modulo operation to prevent integer overflow
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
            }
        }
    }
    return C;
}

// Function to perform matrix exponentiation
vector<vector<long long>> power(const vector<vector<long long>>& A, long long n) {
    if (n == 1) return A; // Base case: power of 1
    vector<vector<long long>> half = power(A, n / 2); // Recursive call to calculate half power
    vector<vector<long long>> result = multiply(half, half); // Multiply matrix by itself
    if (n % 2 == 1) result = multiply(result, A); // If power is odd, multiply by original matrix once more
    return result;
}

class Solution {
public:
    // Function to find the nth Fibonacci number
    int solve(int A) {
        if (A <= 1) return A; // Base cases: Fibonacci numbers at indices 0 and 1 are 0 and 1 respectively
        vector<vector<long long>> base = {{1, 1}, {1, 0}}; // Base matrix representing Fibonacci sequence
        vector<vector<long long>> result = power(base, A - 1); // Calculate power of base matrix
        return result[0][0]; // Return the Fibonacci number at index A
    }
};

// Sample Usage
#include <iostream>
int main() {
    Solution obj;
    int n = 5;
    std::cout << "Fibonacci number at index " << n << ": " << obj.solve(n) << std::endl; // Output: 5
    return 0;
}
