/*
Longest Subarray Length
Programming
Hashing
Medium
61.9% Success

248

21

Bookmark
Asked In:
Problem Description
 
 

Given an integer array A of size N containing 0's and 1's only.

 
You need to find the length of the longest subarray having count of 1’s one more than count of 0’s.


Note: In the subarray count of 1's should be one more than the count of 0's.

 



Problem Constraints
1 <= N <= 105



Input Format
First and only argument is an integer array A of size N.



Output Format
Return an integer denoting the longest length of the subarray.



Example Input
Input 1:

 A = [0, 1, 1, 0, 0, 1]
Input 2:

 A = [1, 0, 0, 1, 0]


Example Output
Output 1:

 5
Output 2:

 1


Example Explanation
Explanation 1:

 Subarray of length 5, index 1 to 5 i.e 1, 1, 0, 0, 1. Count of 1 = 3, Count of 0 = 2.
Explanation 2:

 Subarray of length 1 will be only subarray that follow the above condition.

*/

/*
 * Intuition:
 * - We convert all 0s in the array to -1 to simplify the problem.
 * - We maintain a running sum variable 'sum' to keep track of the sum of elements encountered so far.
 * - We also use an unordered map 'mp' to store the running sum as the key and its corresponding index as the value.
 * - We iterate through the array, updating the running sum and checking if the current sum equals 1. If it does, we update 'res' to the current index + 1.
 * - If the running sum minus 1 is found in the map, we update 'res' to the maximum of 'res' and the difference between the current index and the index stored in the map for the running sum minus 1.
 * - Finally, we return 'res', which represents the length of the longest contiguous subarray with equal number of 0s and 1s.
 * 
 * Time Complexity: O(N)
 * - The algorithm iterates through the array once, so the time complexity is linear.
 * 
 * Space Complexity: O(N)
 * - We use an unordered map to store the running sum and its corresponding index, which can grow up to the size of the input array.
 */

int Solution::solve(vector<int> &A) {
    int n = A.size();
    
    // Convert all 0s to -1
    for(int i = 0; i < n; i++) {
        if(A[i] == 0)
            A[i] = -1;
    }
    
    int sum = 0, res = 0;
    unordered_map<int, int> mp;
    
    // Iterate through the array
    for(int i = 0; i < n; i++) {
        // Update the running sum
        sum += A[i];
        
        // If the current sum equals 1, update 'res'
        if(sum == 1)
            res = i + 1;
        
        // Store the running sum and its index in the map
        if(mp.find(sum) == mp.end())
            mp[sum] = i;
        
        // If the running sum minus 1 is found in the map, update 'res'
        if(mp.find(sum - 1) != mp.end())
            res = max(res, i - mp[sum - 1]);
    }
    
    return res;
}