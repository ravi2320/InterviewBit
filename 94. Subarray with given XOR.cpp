/*
Subarray with given XOR
Programming
Hashing
Medium
53.7% Success

802

16

Bookmark
Asked In:
Problem Description
 
 

Given an array of integers A and an integer B.

Find the total number of subarrays having bitwise XOR of all elements equals to B.



Problem Constraints
1 <= length of the array <= 105

1 <= A[i], B <= 109



Input Format
The first argument given is the integer array A.

The second argument given is integer B.



Output Format
Return the total number of subarrays having bitwise XOR equals to B.



Example Input
Input 1:

 A = [4, 2, 2, 6, 4]
 B = 6
Input 2:

 A = [5, 6, 7, 8, 9]
 B = 5


Example Output
Output 1:

 4
Output 2:

 2


Example Explanation
Explanation 1:

 The subarrays having XOR of their elements as 6 are:
 [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], [6]
Explanation 2:

 The subarrays having XOR of their elements as 5 are [5] and [5, 6, 7, 8, 9]

*/

/*
Intuition:
- The problem requires finding the count of subarrays with XOR equal to `B`.
- We use a hash map to store the XOR of all elements up to the current index.
- If the XOR of a subarray from the start to the current index is `xr` and we want the XOR to be `B`, we need to find a prefix with XOR `xr ^ B`.
- By maintaining the count of such prefixes, we can efficiently find the required subarrays.

Approach:
1. Initialize a hash map to store the XOR of elements up to the current index and their counts.
2. Iterate through the array, calculating the XOR at each step.
3. Check if the XOR of the current subarray (from the start to the current index) XOR `B` exists in the hash map.
4. If it exists, add the count of such prefixes to the result.
5. Update the hash map with the current XOR.
6. Continue this process until the end of the array and return the count of subarrays.

Time Complexity:
- O(n): We traverse the array once, and each hash map operation (insert and find) takes O(1) on average.

Space Complexity:
- O(n): In the worst case, we may store all the XOR values in the hash map.

*/

int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int cnt = 0;  // To store the count of subarrays with XOR equal to B
    int xr = 0;  // To store the XOR of elements up to the current index
    unordered_map<int, int> mp;  // Hash map to store XOR and their counts
    mp[xr]++;  // Initialize the hash map with XOR 0

    for(int i = 0; i < n; i++){
        xr ^= A[i];  // Update the XOR with the current element
        int x = xr ^ B;  // Calculate the required XOR to form B
        cnt += mp[x];  // Add the count of such prefixes to the result
        mp[xr]++;  // Update the hash map with the current XOR
    }

    return cnt;  // Return the count of subarrays with XOR equal to B
}
