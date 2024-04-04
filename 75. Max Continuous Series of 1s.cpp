/*
Max Continuous Series of 1s
Programming
Two Pointers
Medium
39.1% Success

222

18

Bookmark
Asked In:
Problem Description
 
 

Given a binary array A, find the maximum sequence of continuous 1's that can be formed by replacing at-most B zeroes.

For this problem, return the indices of maximum continuous series of 1s in order.

If there are multiple possible solutions, return the sequence which has the minimum start index.



Problem Constraints
 0 <= B <= 105

 1 <= size(A) <= 105

 0 <= A[i] <= 1



Input Format
First argument is an binary array A.

Second argument is an integer B.



Output Format
 Return an array of integers denoting the indices(0-based) of 1's in the maximum continuous series.



Example Input
Input 1:

 A = [1 1 0 1 1 0 0 1 1 1 ]
 B = 1
Input 2:

 A = [1, 0, 0, 0, 1, 0, 1]
 B = 2


Example Output
Output 1:

 [0, 1, 2, 3, 4]
Output 2:

 [3, 4, 5, 6]


Example Explanation
Explanation 1:

 Flipping 0 present at index 2 gives us the longest continous series of 1's i.e subarray [0:4].
Explanation 2:

 Flipping 0 present at index 3 and index 5 gives us the longest continous series of 1's i.e subarray [3:6].
*/

#include <numeric> // Include the numeric header for iota function

/*
Intuition:
We iterate through the array A using two pointers i and j to maintain a sliding window.
We keep track of the count of zeros within the window. If the count exceeds B, we adjust the window by moving the left pointer i.
We update the maximum length of consecutive ones found so far and the corresponding indices.
If the total number of zeros in the array is less than or equal to B, we return all indices as the result.

Time Complexity: O(N)
- We iterate through the array once using two pointers, which takes O(N) time.

Space Complexity: O(N)
- We use extra space to store the result vector, which has a maximum size of N.

*/

vector<int> Solution::maxone(vector<int> &A, int B) {
    int cnt = 0, i = 0, ans = 0, new_i, new_j;
    int total_zeroes = 0; // Variable to store the total number of zeroes
    
    // Calculate the total number of zeroes in the array
    for(int num : A) {
        if(num == 0)
            total_zeroes++;
    }
    
    // Check if B exceeds the total number of zeroes
    if(B >= total_zeroes) {
        vector<int> res(A.size());
        iota(res.begin(), res.end(), 0); // Fill the result vector with indices from 0 to A.size()-1
        return res;
    }

    // Sliding window approach
    for(int j = 0; j < A.size(); j++) {
        
        if(A[j] == 0)
            cnt++;
            
        while(cnt > B) {
            if(A[i] == 0)
                cnt--;
                
            i++;
        }
        
        // Update the maximum length of consecutive ones and corresponding indices
        if(ans < (j - i + 1)) {
            ans = (j - i + 1);
            new_i = i;
            new_j = j;
        }
    }
    
    // Create the result vector with indices corresponding to the maximum length of consecutive ones
    vector<int> res;
    for(int idx = new_i; idx <= new_j; idx++) {
        res.push_back(idx);
    }
    return res;
}
