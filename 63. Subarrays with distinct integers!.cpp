/*
Subarrays with distinct integers!
Programming
Two Pointers
Medium
59.5% Success

343

16

Bookmark
Asked In:
Problem Description

Given an array A of positive integers,call a (contiguous,not necessarily distinct) subarray of A good if the number of different integers in that subarray is exactly B.

(For example: [1, 2, 3, 1, 2] has 3 different integers 1, 2 and 3)

Return the number of good subarrays of A.



Problem Constraints
1 <= |A| <= 40000

1 <= A[i] <= |A|

1 <= B <= |A|



Input Format
The first argument given is the integer array A.

The second argument given is an integer B.



Output Format
Return an integer denoting the number of good subarrays of A.



Example Input
Input 1:

 A = [1, 2, 1, 2, 3]
 B = 2
Input 2:

 A = [1, 2, 1, 3, 4]
 B = 3


Example Output
Output 1:

 7
Output 2:

 3


Example Explanation
Explanation 1:

  Subarrays formed with exactly 2 different integers: [1, 2], [2, 1], [1, 2], [2, 3], [1, 2, 1], [2, 1, 2], [1, 2, 1, 2].
Explanation 2:

  Subarrays formed with exactly 3 different integers: [1, 2, 1, 3], [2, 1, 3], [1, 3, 4].

*/

// Function to count subarrays with at most B distinct elements using sliding window
// Intuition:
// - We use the sliding window technique to count the number of subarrays with at most B distinct elements.
// - We maintain a window using two pointers i and j, where i denotes the left boundary of the window and j denotes the right boundary.
// - As we expand the window to the right, we keep track of the count of distinct elements using a hash map (unordered_map).
// - Whenever the number of distinct elements in the window exceeds B, we shrink the window from the left until it contains at most B distinct elements.
// - We count the number of valid subarrays ending at index j and update the total count accordingly.
// - Finally, we return the count of subarrays with at most B distinct elements.

int slidingWindow(vector<int> &A, int B) {
    int n = A.size();
    int i = 0, j = 0, count = 0;
    unordered_map<int, int> mp;
    
    while (j < n) {
        mp[A[j]]++;
        
        // Shrink the window from the left until it contains at most B distinct elements
        while (mp.size() > B) {
            mp[A[i]]--;
            if (mp[A[i]] == 0)
                mp.erase(A[i]);
            i++;
        }
        
        // Count the number of valid subarrays ending at index j and update the total count
        count += j - i + 1;
        j++;
    }
    
    return count;
}

// Function to count subarrays with exactly B distinct elements
// Intuition:
// - The count of subarrays with exactly B distinct elements is equal to the count of subarrays with at most B distinct elements
//   minus the count of subarrays with at most B-1 distinct elements
// - We use the slidingWindow function to calculate both counts and return their difference
int Solution::solve(vector<int> &A, int B) {
    return slidingWindow(A, B) - slidingWindow(A, B - 1); 
}
