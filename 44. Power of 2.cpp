/*
Power of 2
Programming
Strings
Medium
30.3% Success

128

205

Bookmark
Asked In:
Problem Description
 
 

Find if the given number is a power of 2 or not. More specifically, find if the given number can be expressed as 2^k where k >= 1.
Note: The number length can be more than 64, which means the number can be greater than 2 ^ 64 (out of long long range)


Problem Constraints
1 <= |A| <= 104


Input Format
The first argument is a string A.


Output Format
Return 1 if the number is a power of 2 else return 0


Example Input
128


Example Output
1


Example Explanation
128 can be expressed as 2 ^ 7.
*/

class Solution:
	def power(self, A):
        num = int(A)
        if(num <= 1):
            return 0
        if num & num-1 == 0:
            return 1
        return 0
